#include<bits/stdc++.h>
using namespace std;

void dfs(int i, map<int, bool> &visited, unordered_map<int, list<int>> adjlist){
    visited[i]=1;

    for(auto j: adjlist[i]){
        if(!visited[j]){
            dfs(j, visited, adjlist);
        }
    }

}

int main(){
    unordered_map<int, list<int>> adjlist;

    int n, q;
    cin>>n>>q;

    for(int i=0;i<q;i++){
        int a, b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }    

    map<int, bool> visited;
    for(int i=1;i<n;i++) visited[i]=0;
    
    int count=0;
    for(int i=1;i<n;i++){
        if(!visited[i]){
            dfs(i, visited, adjlist);
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}