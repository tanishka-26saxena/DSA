//KAHN'S ALGORITHM FOR TOPOLOGICAL SORTING
//we basically use the concept of indegree where we maintain the indegree of each node
//then we push the nodes with indegree 0 into a queue
//then we pop the nodes from the queue and push their adjacent nodes into the queue if their indegree becomes 0
//we repeat this process until the queue is empty

//Step wise process
//step 1: create an adjacency list and an indegree array
//step 2: push all the nodes with indegree 0 into a queue
//step 3 : pop the nodes from the queue and push their adjacenct nodes into the queue if their indegree becomes 0
//step 4: repeat step 3 until the queue is empty


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class graph{
    public:
    vector<int> indegree;
    unordered_map<int , vector<int>> adjList;
    vector<int> topoSort;

    void adjacencyList(int V , vector<vector<int>>& edges){
        indegree.resize(V, 0);
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
    }

    void TopoSort(int V){

        queue<int> q;

        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topoSort.push_back(node);

            for(int n : adjList[node]){
                indegree[n]--;
                if(indegree[n] == 0){
                    q.push(n);
                }
            }

        }
    }

};

int main(){
    int V;
    cout << "Enter number of nodes:";
    cin >> V;

    int E;
    cout <<"Enter number of edges:";
    cin >> E;

    vector<vector<int>> edges(E , vector<int>(2));

    cout<< "enter edges ";

    for(int i = 0 ;i < E ; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    graph g;
    g.adjacencyList(V , edges);
    g.TopoSort(V);

    cout << "Topo Sort:";

    for(int node : g.topoSort){
        cout<< node << " ";
    }

    return 0;
}