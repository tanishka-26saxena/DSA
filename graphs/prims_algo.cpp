 //PRIMS ALGORITHM
//Only works with undirected graphs
//Helps you find the minimum spanning tree in a weighted undirected graph

//Steps :
//1. Create an adjacency list: adj[node] = {{neighbor, weight}, ... }
//2. Use a min-heap priority_queue storing {weight, node , parent}.
//3. Use a visited array to track included nodes in the MST.
//4. Start from any node (e.g., node 0), push {0, 0 , -1} into the heap (weight 0 to start....and parent -1 means it has no edge and is the start node ).
//5. While the queue isn't empty:
//   - Pop the node with the smallest weight.
//   - If already visited, continue.
//   - Mark it as visited and add its weight to the total MST cost.
//   - For each neighbor, if not visited, push {edge weight, neighbor} into
//     the heap.
//6. Repeat until all nodes are included in the MST.
//7. The total cost accumulated is the weight of the Minimum Spanning Tree.


#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class graph{
    public :

    vector<vector<pair<int , int>>> adj;
    void adjacencyList(int V , vector<vector<int>> edges){
        adj.resize(V);
        for(auto e : edges){
            adj[e[0]].push_back({e[1] , e[2]});
            adj[e[1]].push_back({e[0] , e[2]});
        }
    }

    int MST(int V){

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        vector<int> vis(V , 0);

        pq.push({0 , 0 , -1}); //{weight , node , parent}
        int cost = 0;

        while(!pq.empty()){
            int wt = pq.top()[0];
            int node = pq.top()[1];
            int parent = pq.top()[2];
            pq.pop();

            if(vis[node] == 1) continue;

            vis[node] = 1;
            cost += wt;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(!vis[adjNode]){
                    pq.push({edgeWt , adjNode , node});
                }
            }
        }

        return cost;
    }

};
int main(){
    int V;
    cout << "enter number of vertices : ";
    cin >> V;

    int E;
    cout << "Enter number of edges : ";
    cin >> E;

    cout << "enter the edges with their cost in the format [u v cost] : "<<endl;
    vector<vector<int>> edges(E , vector<int>(3));

    for(int i = 0 ; i < E ; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    graph g;

    g.adjacencyList(V , edges);

    cout << "MST for the given graph is : " <<g.MST(V)<<endl;

    return 0;
}