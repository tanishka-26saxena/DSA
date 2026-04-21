//BELLMAN FORD ALGORITHM
//Only works with directed graphs
//when a graph contains negative weight edges we cannot use dijkstra's algorithm
//because dijkstra's algorithm fails in graphs with negative weight edges
//so in such cases we use bellman ford algorithm

//Helps to find negative weight cycles in a graph

//edges can be in any order
//we need to relax all the edges sequentially V-1 times where V is the number of vertices

//Steps : 
//1. Initialize distance array where distances from source to all vertices as infinite and distance to source itself as 0
//2. Relax all edges V-1 times i.e. for each edge u-v with weight w, if distance to u + w < distance to v, update distance to v
//3. Check for negative weight cycles by checking if we can relax any edge further


//This will give us the shortest distance from source to all vertices

//Since in a graph of V vertices , in worst case youwill have to take V-1 edge to reach from the first to the last thereby we iterate 
//for V-1 iterations

 //How to detect negative weight cycle?
//After V-1 iterations, if we can still relax any edge,
//i.e. if the distance array values can still be updated,
// it means there is a negative weight cycle in the graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

class graph {
    public:

    vector<int> bellmanFord(int V, int src , vector<vector<int>> edges){
        vector<int> dist(V , 1e9);
        dist[src] = 0;

        for(int i = 0 ; i < V-1 ; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int cost = it[2];

                if(dist[u] != 1e9 && dist[u] + cost < dist[v]){
                    dist[v] = dist[u]+cost;
                }
            }
        } 


        //check for negative weight cycle
        //if we can still relax any edge then it means there is a negative weight cycle
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            if(dist[u] != 1e9 && dist[u] + cost < dist[v]){
                cout << "Negative weight cycle exists";
                return {-1};
            }
        }


        return dist;
    }

};

int main(){
    int V;
    cout<<"enter number of vertices";
    cin >> V;

    int E;
    cout<< "Enter number of edges";
    cin >> E;
    
    cout << "enter the edges with their cost in the format [u v cost] : "<<endl;
    vector<vector<int>> edges(E , vector<int>(3));
    for(int i = 0 ; i < E ; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout<<"enter source : ";
    int src;
    cin >> src;

    graph g;

    vector<int> shortestDist = g.bellmanFord(V , src , edges);

    for(int i = 0 ; i < V ; i++){
        cout << shortestDist[i] << endl;
    }
    
    return 0;

}