#include<bits/stdc++.h>
using namespace std;

class Graph{
    int n;
    unordered_map<int, list<int>> adjList;   
public:
    Graph(int size){
        n=size;
    }

    void addEdge(int u, int v, bool bidir=false){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    // Cycle Detection in Graph - Using DFS
    bool isCyclicDFSutil(int i, unordered_map<int, bool>& visited, unordered_map<int, bool>& stac){
        visited[i]=true;
        stac[i]=true;
        for(auto j:adjList[i]){
            if(!visited[j] && isCyclicDFSutil(j, visited, stac)) return true;
            else if(stac[j]) return true;
        }
        stac[i]=false;
        return false;
    }

    bool isCyclicDFS(){
        unordered_map<int, bool> visited;
        unordered_map<int, bool> stac;
        for(auto i:adjList) visited[i.first]=false;
        
        for(auto i:adjList){
            if(!visited[i.first]){
                if(isCyclicDFSutil(i.first, visited, stac)) return true;
            }
        }
        
        return false;
    }

    // Cycle Detection - Using BFS
    bool isCyclicBFS(){
    
        vector<int> indegree(n, 0);

        for(int i=0;i<n;i++){
            for(auto j:adjList[i]){
                indegree[j]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;
        int count=0;

        while(!q.empty()){
            int t= q.front();
            q.pop();
            topo.push_back(t);

            for(auto i:adjList[t]){
                if(--indegree[i]==0) q.push(i);
            }
            count++;
        }
        
        if(count!=n) return true;
        return false;
    }

    // Cycle Detection Using Topological Sort
    void usingTopo(int u, stack<int>& s, unordered_map<int, bool>& visited){
        visited[u]=true;
        for(auto i:adjList[u]){
            if(!visited[i]){
                usingTopo(i, s, visited);
            }
        }
        s.push(u);
    }

    bool isCyclicTopo(){
        stack<int> s;
        unordered_map<int, bool> visited;
        usingTopo(0, s, visited);

        unordered_map<int, int> loc;

        vector<int> topo;
        int i=0;

        while(!s.empty()){
            topo.push_back(s.top());
            loc[s.top()]=i;
            i++;
            s.pop();
        }

        for(int i=0;i<n;i++){
            for(auto j:adjList[i]){
                if(loc[i] > loc[j]) return true;
            }
        }
        return false;
    }


};

int main(){

    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    if(g.isCyclicTopo()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
}