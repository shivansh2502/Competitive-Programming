#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    unordered_map<int, list<int> > um;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin>>u>>v;
        if(u==1 || v==1){
            if(u==1){
                um[u].push_back(v);
            }
            if(v==1){
                um[v].push_back(u);
            }
        }
        else{
            um[u].push_back(v);
        }
    }

    for(auto i: um){
        int x= i.first;
        for(auto j :um[x]){
            for(auto k: um[j]){
                um[x].push_back(k);
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
        if(!spe[x]){
            spe[x]= true;
            special++;
            for(auto i: um[x]){
                if(a[i-1]== a[x-1] && !spe[i]){
                    special++;
                    spe[i]=true;
                }
            }
        }
        cout<<special<<endl;
    }
    
    return 0;
}
