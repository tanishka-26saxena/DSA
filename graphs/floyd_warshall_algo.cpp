//FLOYD WARSHALL ALGORITHM
//Also known as multi source shortest path algorithm
//Helps you detect negative cycles as well

//it states to go via every other vertex/nodes.
//If going via that node gives you a shorter path then update the distance
//If not then just ignore that node and move to the next node  


//STEPS : 
//1. Initialize a 2D distance array dist[][] where dist[i][j] is the weight of the edge from vertex i to vertex j.
//   If there is no edge between i and j, set dist[i][j] to infinity (or a very large value).
//   Set dist[i][i] to 0 for all vertices i.
//2. For each vertex k from 0 to V-1 (considering each vertex as an intermediate point):
//   For each vertex i from 0 to V-1:
//     For each vertex j from 0 to V-1: 
//       If dist[i][k] + dist[k][j] < dist[i][j]:
//         Update dist[i][j] = dist[i][k] + dist[k][j]
//3. After considering all vertices as intermediate points, dist[i][j] will contain the shortest distance from vertex i to vertex j.
//4. To detect negative weight cycles, check if dist[i][i] < 0 for any vertex i after the algorithm completes.

//How to detect negative weight cycle?
//After the algorithm is complete, if dist[i][i] < 0 for any vertex i,
//it indicates the presence of a negative weight cycle in the graph.



#include <iostream>
#include <vector>
using namespace std;

class graph{
    public:

    vector<vector<int>> adjMatrix;
    void adjacencyMatrix(int V , vector<vector<int>> edges){
        adjMatrix.resize(V , vector<int>(V , 1e9));
        for(auto e :edges){
            adjMatrix[e[0]][e[1]] = e[2];
        }

    }

    vector<vector<int>> floydWarshall(int V){
        vector<vector<int>> dist(V , vector<int>(V , 1e9));

        for(int i = 0 ; i < V ; i++){
            for(int j = 0 ; j < V ; j++){
                if(i == j){
                    dist[i][j] = 0;
                    adjMatrix[i][j] = 0;
                }
                else if(adjMatrix[i][j] != 1e9){
                    dist[i][j] = adjMatrix[i][j];
                }
            }
        }

        for(int via = 0; via < V ; via++){
            for(int i = 0 ; i < V ; i++){
                for(int j = 0 ; j < V ; j++){
                    if(dist[i][via] != 1e9 && dist[via][j] != 1e9 && 
                        dist[i][via] + dist[via][j] < dist[i][j]){
                        dist[i][j] = dist[i][via] + dist[via][j];
                    }
                }
            }
        }

        //checking for negative weight cycle
        for(int i = 0 ; i < V ; i++){
            if(dist[i][i] < 0){
                cout<< " negative cycle detected";
                return {{}};
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

    graph g;

    g.adjacencyMatrix(V , edges);

    vector<vector<int>> shortestDist = g.floydWarshall(V);

    for(int i = 0 ; i < V ; i++){
        for(int j = 0 ; j < V ; j++){
            if(shortestDist[i][j] == 1e9){
                cout << "INF" << " ";
            }
            else{
                cout << shortestDist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;

}