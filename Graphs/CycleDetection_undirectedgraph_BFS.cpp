#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    unordered_map<T,list<T>> adjlist;

public:
    void addedge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    bool isCyclePresent(T src){
        unordered_map<T,bool> visited;
        unordered_map<T,T> parent;
        queue<T> q;

        visited[src]=true;
        parent[src]=src;
        q.push(src);

        while(!q.empty()){
            T top=q.front();
            q.pop();

            for(auto neighbour:adjlist[top]){
                if(visited[neighbour]==true && parent[top]!=neighbour){
                    return true;
                }
                else if(!visited[neighbour]){
                    visited[neighbour]=true;
                    parent[neighbour]=top;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }

};

int main(){
    graph <int>g;
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(2,4);
    //g.addedge(4,1);

    cout<<g.isCyclePresent(1);
    return 0;
}