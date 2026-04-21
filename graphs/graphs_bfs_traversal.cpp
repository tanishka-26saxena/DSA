#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <list>
using namespace std;



// Function to prepare the adjacency list
void prepareAdjList(unordered_map<int, list<int>> &adjList, const vector<pair<int, int>> &edges) {
    for (const auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// Function to perform BFS on the graph
void bfs(const unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true; // Mark the node as visited

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        // Traverse all adjacent nodes
        for (int neighbor : adjList.at(frontNode)) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true; // Mark the neighbor as visited
            }
        }
    }
}

// Function to initiate BFS traversal from all nodes
vector<int> bfsTraversal(int n, const vector<pair<int, int>> &edges) {
    vector<int> ans;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    // Prepare adjacency list from edges
    prepareAdjList(adjList, edges);

    // Initialize all nodes as not visited
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }

    // Perform BFS for all components of the graph
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;  // Return the BFS traversal result
}

int main() {
    // Number of nodes
    int n;
    cout<<"enter the number f nodes"<<endl;
    cin>>n;
    
    // Edges of the graph
    vector<pair<int, int>> edges;
    int u,v;

    cout<<"enter no of edges in pairs"<<endl;
    int x;
    cin>>x;

    for(int i=0; i<x ; i++)
    {
        cout<<"enter edge";
        cin>>u>>v;
        edges.push_back({u,v});
    }

    // Call bfsTraversal to get the BFS order
    vector<int> result = bfsTraversal(n, edges);

    // Print the BFS traversal result
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
