#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,k;
    cin>>n>>k;
    ll a[n];
    unordered_map<ll, ll> um;
    ll count=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        um[a[i]]=i;
    }
    for(int i=0;i<n;i++){
        if(a[i]!=n-i && count<k){
            int t=um[n-i];
            int x=a[i];
            swap(a[i],a[t]);
            um[n-i]=i;
            um[x]=t;
            count++;
        }
    }

    for(ll i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}