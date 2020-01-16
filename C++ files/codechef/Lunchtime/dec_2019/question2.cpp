#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll s[n];
        vector<pair<ll, ll>> v;
        for(ll i=0;i<n;i++){
            cin>>s[i];
            v.push_back(make_pair(s[i],i));
        }
        sort(v.begin(),v.end());
        ll prev_min=0;
        ll ans=0;
        ll size=n;
        for(auto i : v){
            if(i.second>size){
                continue;
            }
            ans+=(i.first-prev_min)*size;
            size=i.second;
            prev_min=i.first;
            // cout<<size<<" "<<prev_min<<" "<<ans<<endl;
            if(size==0){
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}