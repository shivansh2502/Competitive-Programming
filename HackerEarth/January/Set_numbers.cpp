#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll powe[100005]={0};

ll power(ll x,ll y) 
{ 
    if(powe[y]!=0){
        return powe[y];
    }
    else if( y == 0){
        powe[y]=1;
        return powe[y];
    }  
    powe[y/2] = power(x, y/2); 
    if (y%2 == 0) 
        powe[y]=powe[y/2]*powe[y/2];

    else
        powe[y]=x*powe[y/2]*powe[y/2];
    return powe[y];
} 

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        ll bits1=__builtin_popcount(n);
        ll p=0;
        while(power(2,p)<=n){
            p++;
        }
        if(bits1==p){
            cout<<n<<endl;
            continue;
        }
        ll ans=0;
        for(ll i=0;i<p-1;i++){
            ans+=power(2, i);
        }
        cout<<ans<<endl;
    }
}