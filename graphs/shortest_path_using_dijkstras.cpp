// SHORTEST PATH IN DAG USING DIJKSTRA'S 

//to calculate the shortest path using the dijkstra's algorithm we need to just slightly change the algorithm
//along with the priority queue and distance array awe will also use a memoization array called "parent" which will store the 
//parent/previous node that is from where the current node came
//and then just backtrack using this parent array

//Steps:
// 1. Create an adjacency list: adj[node] = {{neighbor, weight}, ... }.
// 2. Use a distance array `dist[]`, initialized with INF, dist[src] = 0.
// 3. Use a priority_queue (min-heap) storing {distance, node}.
// 4. Use a parent array 'parent[]' , initialized with their own indices.
// 4. Pop the node with the smallest distance.
// 5. For each neighbor, if (dist[node] + weight < dist[neighbor]):
//       -> update dist[neighbor]
//       -> update parent[neighbor] with parent node
//       -> push {dist[neighbor], neighbor} into the heap
// 6. Repeat until queue is empty.
// 7. Unreachable nodes remain INF (or mark them as -1).
// 8. Now start from the destination and check parent[destination].
// 9. Keep checking parents until we reach the source and push these parents into the answer array.
// 10. lastly just reverse the answer array to get the path from the source to the destination.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility> 
#include <functional>
#include <algorithm> 
using namespace std;


class graph{
    public:

    unordered_map<int , vector<pair<int , int>>> adj;
    void adjacencyList(int V , vector<vector<int>> edges){
        for(auto e : edges){
            adj[e[0]].push_back({e[1] , e[2]});
            adj[e[1]].push_back({e[0] , e[2]});
        }
    }

    vector<int> dijkstras(int V , int src , int destination){
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        vector<int> dist(V , 1e9);
        vector<int> parent(V , -1);

        pq.push({0 , src});
        dist[src] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWt = it.second;

                if(edgeWt + cost < dist[adjNode]){
                    dist[adjNode] = edgeWt + cost;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode] , adjNode});
                }
                
            }
        }
        
        //printing shortest path
        vector<int> ans;
        int lastNode = destination;
        
        if(dist[destination] == 1e9){
            return {-1};
        }

        while(lastNode != -1){
            ans.push_back(lastNode);
            lastNode = parent[lastNode];
        }

        reverse(ans.begin() , ans.end());
        return ans;
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

    cout << "enter destination : ";
    int destination;
    cin>>destination;

    graph g;
    g.adjacencyList(V , edges);

    vector<int> shortestDist = g.dijkstras(V , src , destination);

    for(int i = 0 ; i < shortestDist.size() ; i++){
        cout << shortestDist[i] << endl;
    }

    return 0;
}