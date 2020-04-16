#include<bits/stdc++.h>
using namespace std;

template<typename T> 
class graph{
    unordered_map<T, list<pair<T,int>>> adjlist;
public:
    void addedge(T u, T v, int dist, bool bidir=true){
        adjlist[u].push_back(make_pair(v,dist));
        if(bidir){
            adjlist[v].push_back(make_pair(u,dist));
        }
    }

    void dijkstraalgo(T src){
        
        unordered_map<T,int> dist;
        for(auto i:adjlist){
            dist[i.first]=INT_MAX;
        }
        unordered_map<T, T> parent;

        dist[src]=0;
        set<pair<int, T>> s;
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            auto p=*(s.begin());
            T node= p.second;
            int nodeDist= p.first;
            s.erase(s.begin());

            for(auto childpair: adjlist[node]){
                if(nodeDist+ childpair.second < dist[childpair.first]){

                    T dest= childpair.first;
                    auto f= s.find(make_pair(dist[dest], dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    parent[dest]=node;

                    dist[dest]= nodeDist+ childpair.second;
                    s.insert(make_pair(dist[dest], dest));

                }
            }
        }
        for(auto d: dist){
            cout<<d.first<<" is located at distance "<< d.second<<" from the source"<<endl;
        }
        for(auto i: parent){
            cout<<i.first<<"->"<<i.second<<",";
            int k=i.second;
            while(parent.count(k)){
                cout<<parent[k]<<",";
                k=parent[k];
            }
            cout<<endl;
        }

    }

};

int main(){

    graph<int> g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.addedge(1,4,7);
    g.dijkstraalgo(1);

    return 0;
}