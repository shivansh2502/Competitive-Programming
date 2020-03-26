#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        unordered_map<ll ,ll> um; 
        ll count=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(!um.count(a[i])){
                um[a[i]]=1;
                count++;
            }
        }
        cout<<count<<endl;
    }

    
    return 0;
}
