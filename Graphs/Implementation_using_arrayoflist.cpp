#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int> *l;
public:
    graph(int vertex){
        v=vertex;
        l=new list<int>[v];
    }
    void addedge(int u, int v, bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    void printlist(){
        for(int i=0;i<v;i++){
            cout<<i<<"->";
            for(int vertex:l[i]){
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(4,3);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(1,3);
    g.printlist();
    return 0;
}