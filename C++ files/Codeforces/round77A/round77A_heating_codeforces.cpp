#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while (t--){
        ll n,sum;
        cin>>n>>sum;
        if(sum<=n){
            cout<<sum*1*1<<endl;
        }
        else{
            ll d=sum/n;
            ll r=sum%n;
            ll ans=0;
            for(ll i=0;i<n;i++){
                if(i<r){
                    ans+=(d+1)*(d+1);
                }
                else{
                    ans+=d*d;
                }
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
}