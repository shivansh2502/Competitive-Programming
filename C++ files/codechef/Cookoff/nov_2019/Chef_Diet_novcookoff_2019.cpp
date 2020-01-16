#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        ll target=0;
        bool flag=true;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        for(ll i=0;i<n;i++){
            target+=a[i];
            if(target>=k){
                target-=k;
            }
            else{
                cout<<"NO "<<i+1<<endl;
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}