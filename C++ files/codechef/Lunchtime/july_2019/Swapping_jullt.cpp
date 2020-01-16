#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n+1]={0};
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        ll dp[n+1];
        dp[0]=0;
        dp[1]=a[1];
        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1] + i*a[i] , dp[i-2] + i*a[i-1] + (i-1)*a[i]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}