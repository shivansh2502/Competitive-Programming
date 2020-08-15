#include<bits/stdc++.h>
using namespace std;


template <typename T>
class graph{
    map<T, list<T>> adjlist;
    map<T, T> level;
    map<T, T> parent;
public:
    void addedge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    } 

    //first for every node calculate its level and parent
    void level_parent(T root){
        parent[root]=-1;
        level[root]=1;
        
        queue<T> q;
        q.push(root);
        map<T, bool> visited;
        visited[root]=true;
        while(!q.empty()){
            T top=q.front();
            q.pop();
            for(auto i: adjlist[top]){
                if(!visited[i]){
                    visited[i]=true;
                    level[i]=level[top]+1;
                    parent[i]=top;
                    q.push(i);
                }
            }
        }
    }
    // find lowest common ancestor without binary lifting
    // time complexity= O(n) , space complexity= O(n)
    T lca(T a, T b){
        if(level[b]<level[a]){
            swap(a, b);
        }
        int d = level[b]- level[a];

        while(d--){
            b= parent[b];  
        }

        if(a==b) return a;

        while(parent[a]!=parent[b]){
            a= parent[a];
            b=parent[b];
        }
        return parent[a];
    }

    

};


int main(){

    graph<int> g;
    g.addedge(1, 2);
    g.addedge(1, 3);
    g.addedge(3, 4);
    g.addedge(3, 5);
    g.addedge(2, 6);
    g.addedge(2, 7);
    g.level_parent(1);
    cout<<g.lca(4, 5);
    
    return 0;
}