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
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(ll i=0;i<n-1;i++){
            if(min(a[i],a[i+1])>k){  
                ll diff=a[i+1]-a[i];
                a[i]=k;
                a[i+1]=k+diff;    
            }
        }
        ll sum=0;
        for(ll i=0;i<n;i++){
            sum+=a[i];
        }
        cout<<sum<<endl;
        
    }
    return 0;
}