//DISJOINT SET UNION BY SIZE

//steps :
//1. create parent and size array
//2. initialize parent of each node to itself and size to 1
//3. for union of two nodes, find their ultimate parents
//4. if they are different, attach smaller size tree under root of larger size tree and
//   increase the size of the new root by the size of the smaller tree
//5. for finding ultimate parent of a node, if the node is not its own parent, recursively call find on its parent
//   also do path compression by making the parent of the node as the ultimate parent found
//6. return the ultimate parent

//Takes logN time for union

//Time complexity : O(4*alpha) where alpha is the inverse Ackermann function which grows very slowly....knowing about alpha is not required
//just say O(4*alpha) or O(4) which is constant time
//Space complexity : O(N) for parent and size array

#include <iostream>
#include <vector>
using namespace std;

class graph{
    public:

    vector<int> size;
    vector<int> parent;

    graph(int n){
        size.resize(n+1 , 1);
        parent.resize(n+1);
        
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        };
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUltimateParent(parent[node]); //path compression
    }

    void unionBySize(int u , int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int main(){
    graph g(7);

    g.unionBySize(1 , 2);
    g.unionBySize(2 , 3);
    g.unionBySize(6 , 7);
    g.unionBySize(5 , 6);
    g.unionBySize(4 , 5);
    cout << "before union of 3 and 7 : "<<endl;
    if(g.findUltimateParent(3) == g.findUltimateParent(7)){
        cout << "same component";
    }
    else{
        cout << "different component";
    }
    cout << endl;
    g.unionBySize(3 , 7);
    cout<<"after union of 3 and 7 : "<<endl;
    if(g.findUltimateParent(3) == g.findUltimateParent(7)){
        cout << "same component";
    }
    else{
        cout << "different component";
    }
    return  0;
}