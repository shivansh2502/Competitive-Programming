#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    unordered_map<T,list<T>> adjlist;
public:
    void addEdge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    bool isCyclicHelper(T node, unordered_map<T,bool> &visited, T parent){
        visited[node]=true;
        for(auto i:adjlist[node]){
            if(!visited[i]){
                if(isCyclicHelper(i, visited, node)==true){
                    return true;
                }
            }
            else if( i!= parent){
                return true;
            }
        }
        return false;
    }

    bool isCyclicBFS(){
        unordered_map<T, bool> visited;
        for(auto i:adjlist){
            T node=i.first;
            if(!visited[node]){
                if(isCyclicHelper(node, visited, node)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
    if(g.isCyclicBFS()==true){
        cout<<"CYCLIC"<<endl;
    }
    else{
        cout<<"NOT CYCLIC"<<endl;
    }
    return 0;
}