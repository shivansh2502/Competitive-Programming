#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    unordered_map<T, list<T>> adjList;
public:
    void addEdge(T u, T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    bool isCyclicHelper(T node, unordered_map<T, bool> &visited, unordered_map<T,bool> &inStack){
        visited[node]=true;
        inStack[node]=true;

        for(auto neighbour:adjList[node]){
            if(!visited[neighbour] && isCyclicHelper(neighbour, visited, inStack)==true || inStack[neighbour]==true){
                return true;
            }
        }
        inStack[node]=false;
        return false;
    }

    bool isCyclicDFS(){
        unordered_map<T,bool> visited;
        unordered_map<T,bool> inStack;

        for(auto i:adjList){
            T node=i.first;
            if(!visited[node]){
                bool cyclePresent=isCyclicHelper(node, visited, inStack);
                if(cyclePresent){
                    cout<<"Cycle is Present"<<endl;
                    return true;
                }
            }
        }
        cout<<"Cycle not Present"<<endl;
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

    g.isCyclicDFS();

    return 0;
}