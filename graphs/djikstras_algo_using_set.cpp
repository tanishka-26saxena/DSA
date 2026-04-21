//DIJKSTRA'S ALGORITHM USING PRIORITY QUEUE
//Find the shortest path from a source node to all other nodes
// Works only for graphs with NON-NEGATIVE edge weights




#include <iostream>
#include <vector>
#include <set> 
#include <utility> 
using namespace std;

class graph{
    public:

    vector<vector<pair<int , int>>> adj;

    void adjacencyList(int V , vector<vector<int>>& edges){
        adj.resize(V);
        for(auto e : edges){
            adj[e[0]].push_back({e[1] , e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
    }

    vector<int> djikstras(int V  , int src){

        set<pair<int , int>> s;
        vector<int> dist(V , 1e9);
        
        s.insert({0 , src});
        dist[src] = 0;

        while(!s.empty()){
            int node = s.begin()->second;
            int cost = s.begin()->first;
            s.erase(s.begin());

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(edgeWt + cost < dist[node]){
                    if(dist[adjNode] != 1e9) {       //this means someone already reached their before too so we need to remove that first
                        s.erase({dist[adjNode] , adjNode});
                    }
                    //and then we can simply update the values and insert the node into the set again with the updated distance value
                    dist[node] = edgeWt + cost;
                    s.insert({dist[adjNode] , adjNode});
                }
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
    g.adjacencyList(V , edges);

    vector<int> shortestDist = g.djikstras(V , src);

    for(int i = 0 ; i < V ; i++){
        cout << i<<":" << shortestDist[i] << endl;
    }

    return 0;
}