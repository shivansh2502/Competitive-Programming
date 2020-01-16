#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m,q;
        cin>>n>>m>>q;
        ll a[n]={0};
        ll b[m]={0};
        for(ll i=0;i<q;i++){
            ll r,c;
            cin>>r>>c;
            a[r-1]++;
            b[c-1]++;
        }
        ll even=0;
        ll odd=0;
        for(ll i=0;i<m;i++){
            if(b[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        
        ll total=0;
        for(ll i=0;i<n;i++){
            if(a[i]%2==0){
                total+=odd;
            }
            else{
                total+=even;
            }
        }
        cout<<total<<endl;
    }

    return 0;
}