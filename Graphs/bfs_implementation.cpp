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

    void bfs(T src){
        queue<T> q;
        map<T,bool> visited;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T top=q.front();
            cout<<top<<" ";
            q.pop();
            for(auto i:adjlist[top]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
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
    g.bfs(0);
    
    return 0;
}