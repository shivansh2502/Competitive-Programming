#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long

ll  powe[1000]={0};

ll  power(ll  x,ll  y) { 
    if(powe[y]!=0) return powe[y];

    if( y == 0){
        powe[y]=1;
        return powe[y];
    }  

    powe[y/2] = power(x, y/2); 

    if (y%2 == 0) powe[y]=powe[y/2]*powe[y/2];

    else powe[y]=x*powe[y/2]*powe[y/2];

    return powe[y];
} 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll l, r;
        cin>>l>>r;
        ll p=0;
        while(l>=power(2,p)){
            p++;
        }
        ll ans=l;
        ll m= 1000000007;
        if(power(2,p)<r){
            ll prev=l;
            int x=p;
            for(ll i=l+1;i<power(2, p);i+=j){
                prev= prev & i;
                ans= ((ans%m)+ (prev%m))%m;
            }
        }
        else{
            ll prev=l;
            for(ll i=l+1;i<=r;i++){   
                prev= prev & i; 
                ans= ((ans%m)+ (prev%m))%m;
            }
        }
        cout<<ans%m<<endl;
    }
    return 0;
}