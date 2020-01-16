#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll a,m;
        cin>>a>>m;
        ll n=m/a;
        vector<ll> v;
        ll diff= m- a*n;
        while(diff<=n){
            if(diff==0){
                diff+=a;
                n--;
                continue;
            }
            if(n%diff==0){
                v.push_back(n);
            }
            diff+=a;
            n--;
        }
        if(v.size()==0){
            cout<<0<<endl;
            cout<<endl;
        }
        else{
            cout<<v.size()<<endl;
            sort(v.begin(), v.end());
            for(auto i : v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}