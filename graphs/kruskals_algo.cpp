//KRUSKAL'S ALGORITHM
//Only works with undirected graphs
//using disjoint set to perform this algorithm
//Helps you find the minimum spanning tree in a weighted undirected graph

//steps :
// 1. Sort all edges in non-decreasing order of their weights.
// 2. Initialize Disjoint Set (DSU/Union-Find):
//      Each vertex is its own parent initially.
//      Use path compression for find() and union by rank/size for efficiency.
// 3. Iterate over edges (u, v, w):
//      If find(u) != find(v), they belong to different sets → no cycle will form.
//          Include this edge in the MST.
//          Union(u, v) to merge the sets.
//      Else skip (adding this edge would form a cycle).
// 4. Repeat until MST has (V – 1) edges.
// 5. Total MST cost = sum of selected edge weights.


#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class graph{
    public:

    vector<int> parent;
    vector<int> rank;

    graph(int V){
        rank.resize(V+1 , 1);
        parent.resize(V+1);

        for(int i = 1 ; i <= V ; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]);
    }

    void disjointSetUnionByRank(int u , int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    int MST(int V , vector<pair<int , pair<int , int>>> edges){
        int mstWt = 0;

        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            //checking if u and v belong to the same component
            //if not we will add up their cost
            if(findUltimateParent(u) != findUltimateParent(v)){
                mstWt += wt;
                disjointSetUnionByRank(u , v);
            }
        }
        return mstWt;


    }
    


};

int main(){

    int V;
    cout<<"enter the number of vertices : ";
    cin >> V;

    int E;
    cout <<"enter the number of edges : ";
    cin >> E;

    cout << "enter the edges with their cost in the format [cost u v] : "<<endl;
    vector<pair<int , pair<int , int>>> edges; //{cost , {u , v}}
    for(int i = 0 ; i < E ; i++){
        int u , v , cost;
        cin >> cost >> u >> v;
        edges.push_back({cost , {u , v}});
    }


    sort(edges.begin() , edges.end());

    
    graph g(V);

    int MST = g.MST(V , edges);
    cout << "Minimum cost of spanning tree is : " << MST << endl;

    return 0;



}