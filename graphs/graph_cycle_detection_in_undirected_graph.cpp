//CYCLE DETECTION IN DIRECTED GRAPH

//In an undirected graph , we can detect a cycle by simply doing a traversal and alongside marking the visited nodes
//when a visited node is encountered which is not the parent of the current node, we can say that a cycle exists in the graph

//But the same logic does not work for directed graphs because in directed graphs, 
//the edges have a direction and we cannot simply check for visited nodes.

//So, we along with marking the visited nodes, we also need to have path_visited to make sure of the path we are currently in
//If we encounter a node which is already in the path_visited, we can say that a cycle exists in the graph
#include<iostream>
#include<unordered_map>
#include<list>
#include <vector>
using namespace std;

class graph {
  public:
    unordered_map<int , vector<int>> adjList;
    bool dfs(int node, vector<int>& visited ,vector<int>& path_visited){
        
        path_visited[node] = 1;
        visited[node] = 1;
        
        for(int i =0 ; i < adjList[node].size() ; i++){
            int curr = adjList[node][i];
            
            if(visited[curr] == 0){
                if(dfs(curr , visited , path_visited)){
                    return true;
                }
            }
            
            if(visited[curr] == 1 && path_visited[curr] == 1){
                return true;
            }
        }
        
        path_visited[node] = 0;
        return false;
    }
    
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        for(auto i : edges){
            adjList[i[0]].push_back(i[1]);
        }
        
        vector<int> visited(V , 0);
        vector<int> path_visited(V, 0);
        
        for(int i=0 ; i< V ; i++){
            if(visited[i] != 1){
                if(dfs(i , visited, path_visited) == true){
                    return true;
                }
                
            }
            
        }
        return false;
    }
};

int main()
{
    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"enter the number of edges"<<endl;
    cin>>m;

    graph g;
    vector<vector<int>> edges;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cout<<"Enter edge (u v): ";
        cin>>u>>v;
        edges.push_back({u,v});
    }

    if(g.isCyclic(n, edges)){
        cout<<"Cycle exists in the graph"<<endl;
    } else {
        cout<<"No cycle exists in the graph"<<endl;
    }

    return 0;
}
