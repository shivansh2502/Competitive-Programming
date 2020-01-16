#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            a[i]=i;
        }
        ll s=0;
        for(ll i=0;i<k;i++){
            ll T;
            cin>>T;
            if(T==1){
                ll y;
                cin>>y;
                y=y+s;
                a[y]=0;
            }
            else if(T==2){
                ll p,q;
                cin>>p>>q;
                p=p+s;
                q=q+s;
                ll maxi=0;
                for(ll i=p;i<=q;i++){
                    maxi=max(maxi,a[i]);
                }
                cout<<maxi<<endl;
                s=(s+maxi)%n;
            }
        }
    }
    return 0;
}