//DISJOINT SET UNION BY RANK

//difference between rank and height of a tree : rank is an upper bound on the height of the tree
// so rank is always less than or equal to height of the tree

//steps :
//1. create parent and rank array
//2. initialize parent of each node to itself and rank to 0
//3. for union of two nodes, find their ultimate parents
//4. if they are different, attach smaller rank tree under root of higher rank tree and
//   if ranks are same then attach one under the other and increase the rank of the new root by 1
//5. for finding ultimate parent of a node, if the node is not its own parent, recursively call find on its parent
//   also do path compression by making the parent of the node as the ultimate parent found
//6. return the ultimate parent

//Takes logN time for union

//Time complexity : O(4*alpha) where alpha is the inverse Ackermann function which grows very slowly....knowing about alpha is not required
//just say O(4*alpha) or O(4) which is constant time
//Space complexity : O(N) for parent and rank array

#include <iostream>
#include <vector>
using namespace std;

class graph{
    public:

    vector<int> parent;
    vector<int> rank;

    graph(int n){
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]); //path compression
    }

    void unionByRank(int u , int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v){
            return ;
        }

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

};

int main(){

    graph g(7);
    g.unionByRank(1 , 2);
    g.unionByRank(2 , 3);
    g.unionByRank(4 , 5);
    g.unionByRank(6 , 7);
    g.unionByRank(5 , 6);

    cout << "before union of 3 and 7 : "<<endl;
    if(g.findUltimateParent(3) == g.findUltimateParent(7)){
        cout << "same component";
    }
    else{
        cout << "different component";
    }

    cout << endl;
    cout<<"after union of 3 and 7 : "<<endl;
    g.unionByRank(3 , 7);

    if(g.findUltimateParent(3) == g.findUltimateParent(7)){
        cout << "same component";
    }
    else{
        cout << "different component";
    }

    return  0;
}