#include<bits/stdc++.h>
using namespace std;


template <typename T>
class graph{
    map<T, list<T>> adjlist;
public:
    void addedge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    } 

    void dfsHelper(T src, map<T, bool>& visited){
        visited[src]=true;
        for(auto i:adjlist[src]){
            if(!visited[i]){
                dfsHelper(i, visited);
            }
        }
        cout<<src<<" ";
        return;
    }

    void dfs(T src){
        map<T, bool> visited;
        for(auto i: adjlist){
            visited[i.first]=false;
        }
        dfsHelper(src, visited);
        return;
    }

};

int main(){

    graph<int> g;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,4);
    g.addedge(2,4);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(3,5);
    g.dfs(0);


    return 0;
}