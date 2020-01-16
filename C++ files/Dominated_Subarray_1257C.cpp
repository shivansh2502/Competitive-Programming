#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        unordered_map<ll,ll> um;
        ll mincount=INT_MAX;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(um.find(a[i])==um.end()){
                um[a[i]]=i;
            }
            else{
                if(i-um[a[i]]+1<mincount){
                    mincount=i-um[a[i]]+1;
                }
                um.erase(a[i]);
                um[a[i]]=i;
            }
        }
        if(mincount==INT_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<mincount<<endl;
        }
    }
    return 0;
}