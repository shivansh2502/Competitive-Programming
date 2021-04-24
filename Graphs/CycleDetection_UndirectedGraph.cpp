#include<bits/stdc++.h>
using namespace std;


class Graph{
    int v;
    unordered_map<int, list<int>> adjList;
public:

    Graph(int size){
        v=size;
    }

    void addEdge(int u, int v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir) adjList[v].push_back(u);
    }

    // Cycle Detection using DFS
    // any adjacent node which is visited but not parent means graph is cyclic
    bool isCyclicDFSUtil(int child, unordered_map<int, bool>& visited, int parent){
        visited[child]=true;

        for(auto neighbours: adjList[child]){
            if(!visited[neighbours]){
                if(isCyclicDFSUtil(neighbours, visited, child)) return true;
            }
            else if(neighbours!=parent) return true;
        }
        return false;
    }

    bool isCyclicDFS(){
        unordered_map<int, bool> visited;

        for(int i=0;i<v;i++) visited[i]=false;

        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(isCyclicDFSUtil(i, visited, -1)) return true;
            }
        }
        return false;
    }

    // Cycle Detection using BFS
    // any adjacent node which is visited but not parent means graph is cyclic
    bool isCyclicBFS(){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        for(int i=0;i<v;i++){
            parent[i]=-1;
            visited[i]=false;
        }

        queue<int> q;
        q.push(0);
        visited[0]=true;

        while(!q.empty()){
            int t= q.front();
            q.pop();
            
            for(auto i:adjList[t]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                    parent[i]=t;
                }
                else if(parent[t]!=i) return true;
            }
        }

        return false;
    }
};

int main(){
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    if(g.isCyclicBFS()) cout<<"Cycle Detected in Graph"<<endl;
    else cout<<"No Cycle Detected"<<endl;

    return 0;
}