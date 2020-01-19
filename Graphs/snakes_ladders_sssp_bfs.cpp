#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph{
    map<T, list<T>> adjlist;
public:
    void addedge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    } 

    int bfs(T src,T dest){
        queue<T> q;
        map<T,int> distance;
        map<T,T> parent;
        for(auto i:adjlist){
            distance[i.first]=INT_MAX;
        }

        q.push(src);
        distance[src]=0;
        parent[src]=src;

        while(!q.empty()){
            T node=q.front();
            // cout<<node<<" ";
            q.pop();
            for(auto i:adjlist[node]){
                if(distance[i]==INT_MAX){
                    // cout<<"Pushing"<<i<<endl;
                    q.push(i);
                    distance[i]=distance[node]+1;
                    parent[i]=node;
                }
            }
        }
        // for(auto i:adjlist){
        //     T node=i.first;
        //     cout<<"Distance of "<<node<<"is "<<distance[node]<<endl;
        // }
        T temp=dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp=parent[temp];
        }
        cout<<src<<endl;
        return distance[dest];
    }
};

int main(){
    graph<int> g;
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;

    for(int u=0;u<=36;u++){
        for(int die=1;die<=6;die++){
            int v=u+die+board[u+die];
            g.addedge(u,v,false);
        }
    }

    cout<<"The shortest distance is "<<g.bfs(1,36)<<endl;

    return 0;
}