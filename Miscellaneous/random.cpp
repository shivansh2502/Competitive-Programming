#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

void check(unordered_map<int, list<int>> um, bool *spe, int &special, int x , int a[], int value){
    for(auto i: um[x]){
        if(a[i-1]==value && !spe[i]){
            special++;
            spe[i]=true;
        }
        if(um.count(i)) check(um, spe, special, i, a, value);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    unordered_map<int, list<int>> umap;

    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;  
        umap[u].push_back(v);
        umap[v].push_back(u);
    }

    unordered_map<int, list<int>> um;
    queue<int> que;
    unordered_set<int> s;
    que.push(1);
    while(!que.empty()){
        int x= que.front();
        que.pop();
        s.insert(x);
        for(auto i: umap[x]){
            if(!s.count(i)){
                um[x].push_back(i);
                que.push(i);
            }
        }
    }

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int q;
    cin>>q;
    int special=0;
    bool spe[n+1]={false};
    while(q--){
        int x;
        cin>>x;
        if(special==n){
            cout<<special<<endl;
        }
        else{
            if(!spe[x]){
                spe[x]= true;
                special++;
                check(um, spe, special, x, a, a[x-1]);
            }
            cout<<special<<endl;
        }
    }
    return 0;
}
