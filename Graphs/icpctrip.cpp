#include<bits/stdc++.h>
using namespace std;

template<typename T>
class route{
public:
    T dest;
    int train;
    int flight;

    route(T d, int t, int f){
        dest=d;
        train=t;
        flight=f;
    }
};
template<typename T>
class graph{
    unordered_map<T, list<route<T>>> adjlist;
public:
    void addedge(T u, T v, int train, int flight){
        route<T> r(v, train, flight);
        route<T> s(u, train, flight);
        adjlist[u].push_back(r);
        adjlist[v].push_back(s);
    }

    unordered_map<T, int> dijkstraalgo(T src){
        unordered_map<T, int> dist;
        for(auto i: adjlist){
            dist[i.first]=INT_MAX;
        }

        set<pair<int,T>> s;
        dist[src]=0;
        s.insert(make_pair(0,src));

        while(!s.empty()){
            auto node=*(s.begin());
            int nodedist=node.first;
            T nodevalue=node.second;
            s.erase(s.begin());
            for(auto i: adjlist[nodevalue]){
                if(dist[i.dest] > dist[nodevalue]+i.train){

                    auto x=s.find(make_pair(dist[i.dest], i.dest));
                    if(x!=s.end()){
                        s.erase(x);
                    }
                    dist[i.dest]= dist[nodevalue]+i.train;
                    s.insert(make_pair(dist[i.dest], i.dest));
                }
            }
        }
        return dist;
    }

    int icpctrip(T source, T destination){
        unordered_map<T, int> d1=dijkstraalgo(source);
        unordered_map<T, int> d2=dijkstraalgo(destination);

        vector<int> v;
        int ans=INT_MAX;
        for(auto i: adjlist){
            for(auto j:adjlist[i.first]){
                cout<<i.first<<"-->"<<d1[i.first]+j.flight+d2[j.dest]<<endl;
                if(ans>d1[i.first]+j.flight+d2[j.dest]){
                    ans=d1[i.first]+j.flight+d2[j.dest];
                }
            }
        }
        if(ans> d1[destination]){
            ans=d1[destination];
        }
        return ans;
    }
};

int main(){

    graph <string> g;
    g.addedge("Delhi","Mumbai", 100, 200);
    g.addedge("Mumbai","Lukhnow", 150, 300);
    g.addedge("Delhi","Lukhnow", 70, 280);
    g.addedge("Lukhnow","Kanpur", 90, 200);
    g.addedge("Kanpur","Khadagpur", 120, 270);
    g.addedge("Mumbai","Kanpur", 140, 210);
    cout<<g.icpctrip("Delhi", "Khadagpur")<<endl;

    return 0;
}