#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;
    ll a[n]={0};
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll k;
    cin>>k;
    while(k--){
        ll x;
        cin>>x;
        ll sum=0;
        ll start=0;
        ll end=n-1;
        while(start<=end){
            sum+=a[start];
            start++;
            end-=x;
        }
        cout<<sum<<endl;
    }

    return 0;
}