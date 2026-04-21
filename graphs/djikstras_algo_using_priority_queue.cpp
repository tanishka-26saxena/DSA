//DIJKSTRA'S ALGORITHM USING PRIORITY QUEUE
//Find the shortest path from a source node to all other nodes
// Works only for graphs with NON-NEGATIVE edge weights

//Steps:
// 1. Create an adjacency list: adj[node] = { {neighbor, weight}, ... }.
// 2. Use a distance array `dist[]`, initialized with INF, dist[src] = 0.
// 3. Use a priority_queue (min-heap) storing {distance, node}.
// 4. Pop the node with the smallest distance.
// 5. For each neighbor, if (dist[node] + weight < dist[neighbor]):
//       → update dist[neighbor]
//       → push {dist[neighbor], neighbor} into the heap
// 6. Repeat until queue is empty.
// 7. Unreachable nodes remain INF (or mark them as -1).


//Time complexity for it
//O(V * (pop vertices from min heap + no. of edges in each vertex * push into priority queue))
//O(V* (log(heap size) + n*edges * log(heap size)))
//O(V* log(heap size) * (1 + n*edges)))      taking log(heap size) common
//O(V * log(heap size) * (1+ V - 1))         vertices can have at max V-1 edges 
//O(V* log(heap size) * V)
//O(V^2 * log(heap size))
//O(V^2 * log(V^2))      heap size will be almost equal to the V^2
//O(V^2 * 2log(V))
//O(E * 2log(V))        understand this as if each vertex is connected to each vertex then V*(V-1) = E
//almost equal to ......O(E*log(V))


#include <iostream>
#include <vector>
#include <queue> 
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
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        vector<int> dist(V , 1e9);

        dist[src] = 0;

        pq.push({0 , src});

        while(!pq.empty()){

            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;

                if(cost + edgeWeight < dist[adjNode]){
                    dist[adjNode] = cost + edgeWeight;
                    pq.push({dist[adjNode] , adjNode});

                }
            }

        }

        for(int i = 0 ; i < V ; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
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