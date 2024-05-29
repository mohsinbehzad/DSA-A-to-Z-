#include<iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        // create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj) {
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter number of Nodes: ";
    cin>>n;

    int m;
    cout<<"Enter number of Edges: ";
    cin>>m;

    Graph g;

    for(int i = 0; i<m; i++){
        int u,v;
        cout<<"Enter two numbers between edge separated by a space: ";
        cin>>u>>v;
        // creating an undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();
}