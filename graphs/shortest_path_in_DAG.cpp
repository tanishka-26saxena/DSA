//SHORTEST PATH IN DIRECTED ACYCLIC GRAPH
//to calculate the path in DAG we simply use toposort to first get the nodes in the stack
//and then while popping the elements from the stack we simply check their adjacent nodes and their path cost and update 
//the distance array for them accordingly
//initially we mark the distances for all the nodes as inifinity
//if the distances of the adjacent nodes in the distance array are greater than the current nodes distance + the adjacent nodes path cost
//we update their distane in the distance array else we already have a better path


// SHORTEST PATH IN DIRECTED ACYCLIC GRAPH (DAG)
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <climits>
using namespace std;

class Graph {
public:
    unordered_map<int , vector<pair<int, int>>> adjList;

    void adjacencyList(vector<vector<int>>& edges) {
        for (auto e : edges) {
            adjList[e[0]].push_back({e[1], e[2]});
        }
    }

    void dfs(int node, vector<int>& vis, stack<int>& s) {
        vis[node] = 1;
        for (auto curr : adjList[node]) {
            int adjNode = curr.first;
            if (!vis[adjNode]) {
                dfs(adjNode, vis, s);
            }
        }
        s.push(node);
    }

    vector<int> calculateDist(int V , int src) {
        vector<int> dist(V , INT_MAX);
        dist[src] = 0;

        // Step 1: Topological Sort
        vector<int> vis(V, 0);
        stack<int> s;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i , vis , s);
            }
        }

        // Step 2: Relax edges in topological order
        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (dist[u] != INT_MAX) {
                for (auto p : adjList[u]) {
                    int v = p.first;
                    int cost = p.second;
                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;
                    }
                }
            }
        }

        // Convert INF to -1 (unreachable)
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices : ";
    cin >> V;

    cout << "Enter the number of edges : ";
    cin >> E;
    
    vector<vector<int>> edges(E , vector<int>(3));
    cout << "Enter the edges in the format [u v cost] :\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter source node : ";
    cin >> src;

    Graph g;
    g.adjacencyList(edges);

    vector<int> MinDistance = g.calculateDist(V , src);

    cout << "\nShortest distances from source (" << src << "):\n";
    for (int i = 0; i < MinDistance.size(); i++) {
        cout << i << " : " << MinDistance[i] << "\n";
    }

    return 0;
}
