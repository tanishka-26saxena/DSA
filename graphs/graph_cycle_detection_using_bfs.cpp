//Cycle detection in a directed graph using BFS (Kahn's Algorithm)
//A directed graph is said to contain a cycle if the topological sort of the graph is not possible.
//so we can use kahns algorithm to detect a cycle in a directed graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


class graph{
    public:

    vector<int> indegree;
    unordered_map<int , vector<int>> adjList;

    void adjacencyList(int V , vector<vector<int>>& edges){
        indegree.resize(V, 0);
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
    }

    bool TopoSort(int V){
        queue <int> q;

        int cnt = 0;

        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            cnt++;
            q.pop();

            for(int n : adjList[node]){
                indegree[n]--;
                if(indegree[n] == 0){
                    q.push(n);
                }
            }
        }

        return (cnt == V);
    }
};

int main(){
    int V;
    cout<<"enter number of nodes:";
    cin >> V;

    int E;
    cout <<"Enter number of edges:";
    cin >>E;

    vector<vector<int>> Edges(E , vector<int>(2));

    for(int i = 0 ;i < E ; i++){
        cin >>Edges[i][0] >> Edges[i][1];
    }

    graph g;
    g.adjacencyList(V , Edges);

    if(g.TopoSort(V)){
        cout<<"No cycle detected";
    }
    else{
        cout<<"cycle detected";
    }

    return 0;
}