//Shortest path in an unweighted graph using BFS
  
//while performing bfs we maintain a queue which stores the node 
//now to find the shortest path with bfs we maintain also push the distance of the node from the source node in the queue
//we also maintain a distance array which stores the distance of each node from the source node

//the distance of the source node from itself is 0
//now we pop the node from the queue and traverse all its adjacent nodes
//if the distance of the adjacent node from the source node is greater than the distance of the current node + 1
//we update the distance of the adjacent node to be distance of current node + 1
//we push the adjacent node and its distance into the queue
//we repeat this process until the queue is empty

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class graph{
    public:
    unordered_map<int , vector<int>> adjList;   
    vector<int> distance;

    //making an adjacency list
    void adjacencyList(int V , vector<vector<int>>& edges){
        for(auto e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
    }

    //performing bfs to find the shortest path

    void bfs(int src , int V){
        //initializing the distance array with infinity value
        distance.resize(V , INT_MAX);

        //making a queue to store the distance and the node
        queue<pair<int , int>> q;
        q.push({src, 0});
        //distance of source node from itself will be 0
        distance[src] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();

            for(int n : adjList[node]){
                //if the distance of the adjacent node is smaller than the 
                //distance of the current node + 1 we do not update it
                //else we update the distance of the adjacent node in the array
                if(dist + 1 < distance[n]){
                    distance[n] = dist+1;
                    q.push({n , dist+1});
                }

            }
        }

        //marking the distance of unreachable nodes as -1
        for(int i = 0 ; i < V ; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
    }
};

int main(){
    int V;
    cout<<"enter the number of vertices : ";
    cin >> V;

    int E;
    cout << "Enter the number of edges : ";
    cin >>E;

    vector<vector<int>> edges(E , vector<int>(2));

    for(int i = 0; i < E ; i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    graph g;
    g.adjacencyList(V, edges);

    int src;
    cout<<"enter the source node:";
    cin >>src;

    g.bfs(src , V);
    cout << "The shortest distance from source node " << src << " to all other nodes is:\n";
    for(int i = 0 ; i < V ; i++){   
        cout << "Node " << i << " : " << g.distance[i] << endl;
    }

    return 0;
}