#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        ll n,k;
        n=3,k=3;
        // cin>>n>>k;
        ll ans=1;
        ll m=1000000007;
        if(k==2){
            if(n==1){
                ans=5;
            }
            else if(n==2){
                ans=25;
            }
            else{
                ans=25;
                ll x=1;
                for(ll i=2;i<n;i++){
                    x=((x%m)*(10%m))%m;
                    ll y=(((x%m)*(5%m))%m*(4%m))%m;
                    ans=(ans%m)+(y%m);
                }
            }
        }
        else if(k==3){
            for(ll i=0;i<n;i++){
                if(i>0){
                    ans= (((ans%m)*(10%m))%m + 1)%m;
                }
            }
            ans=((ans%m)*(3%m))%m;
            ans=ans+1;
        }
        else if(k==4){
            if(n==1){
                ans=3;
            }
            else if(n==2){
                ans=9;
            }
            else if(n==3){
                ans=59;
            }
            else{
                ans=59;
                ll x=10;
                for(ll i=3;i<n;i++){
                    x=((x%m)*(10%m))%m;
                    ll y=((((((x-4)%m/(4%m))%m)*(5%m))%m)*(4%m))%m;
                    ans=(ans%m)+(y%m);
                }
            }
        }
        else if(k==5){
            for(ll i=0;i<n;i++){
                ans=((ans%m)*(2%m))%m;
            }
        }
        else if(k==6){
            if(n==1){
                ans=2;
            }
            else if(n==2){
                ans=8;
            }
            else{
                ans=8;
                ll x=10;
                for(ll i=2;i<n;i++){
                    x=((x%m)*(10%m))%m;
                    ll y=(x%m)/(6%m);
                    ans=(ans%m)+(y%m)+(y%m)+((y-1)%m)+((y-1)%m);
                }
            }

        }
        cout<<ans%m<<endl;
    }
    return 0;
}