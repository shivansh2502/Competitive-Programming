#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    unordered_map<T,list<T>> adjList;
public:
    void addEdge(T u , T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }


    bool isCyclicBFS(T src){
        // unordered_map<T,bool> visited;
        unordered_map<T, list<T>> parent;
        queue<T> q;

        // visited[src]=true;
        q.push(src);

        while(!q.empty()){
            T node=q.front();
            q.pop();
            for(auto i: adjList[node]){
                std::list<int>::iterator iter = std::find (parent[node].begin(), parent[node].end(), i);
                if(iter!=parent[node].end()){
                    // cout<<"Cycle"<<endl;
                   return true;
                }
                // visited[i]=true;
                for(auto j:parent[node]){
                    std::list<int>::iterator iter = std::find (parent[i].begin(), parent[i].end(), j);
                    if(iter==parent[i].end()){
                        parent[i].push_back(j);
                    }
                }
                parent[i].push_back(node);
                q.push(i);
            }
            // cout<<node<<"->";
            // for(auto j:parent[node]){
            //     cout<<j<<" ";
            // }
            // cout<<endl;
        }
        return false;
    }
};

int main(){
    graph <int> g;
    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
    // g.addEdge(3,0,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);

    if(g.isCyclicBFS(0)){
        cout<<"Cycle detected"<<endl;
    }
    else{
        cout<<"No Cycle Present"<<endl;
    }
    return 0;
}