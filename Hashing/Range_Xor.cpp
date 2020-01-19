#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    vector<ll> v;
    while(t--){
        ll type;
        cin>>type;
        if(type==0){
            ll x;
            cin>>x;
            v.push_back(x);
        }
        else if(type==1){
            ll l,r,x;
            cin>>l>>r>>x;
            ll maxvalue=0;
            ll element=0;
            for(ll i=l;i<r;i++){
                ll value=x^v[i];
                if(value>maxvalue){
                    maxvalue=value;
                    element=v[i];
                }
            }
            cout<<element<<endl;
        }
    }
    return 0;
}