//topological sort in graph is used to find a linear ordering of vertices
// such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.

//the algorithm is simple 
//we will use DFS to traverse the graph and push the nodes into a stack while maintaining a visited array.
//also make sure that the nodes are visited only once by checking the visited array.
//the nodes will be pushed into the stack after all their adjacent nodes have been visited.
//finally we will pop the elements from the stack to get the topological sort.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class graph {
  public:
    unordered_map<int , vector<int>> adjList;
    void dfs(int node ,vector<int>& vis , stack<int>& s){
        vis[node] = 1;
        
        for(int curr : adjList[node]){
            if(!vis[curr]){
                dfs(curr , vis, s);
            }
        }
        s.push(node);
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //creating adjacency list first
        
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
        }
        
        //calling DFS for each node
        vector<int> vis(V , 0);
        stack<int> s;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                dfs(i , vis, s);
            }
        }
        
        //popping the values from stack to get the top sort
        
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
        
    }
};

int main(){
    int V;
    cout<<"Enter number of vertices: ";
    cin>>V;

    int E;
    cout<<"Enter number of edges: ";    
    cin>>E;

    vector<vector<int>> edges(E, vector<int>(2));
    cout<<"Enter edges (u v) format:\n";

    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    graph g;

    vector<int> result = g.topoSort(V, edges);

    cout << "Topological Sort: ";
    for(int node : result) {
        cout << node << " ";
    }

    return 0;
}