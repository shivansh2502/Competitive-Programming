#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(pair<ll,ll> v1, pair<ll,ll> v2){
    return v1.second > v2.second;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n][10];
        ll ci[n];
        for(ll i=0;i<n;i++){
            cin>>ci[i];
            for(ll j=0;j<ci[i];j++){
                cin>>a[i][j];
            }
        }
        vector<pair<ll,ll>> v;
        ll amount=0;
        for(ll i=0;i<n;i++){
            if(ci[i]%2==0){
                for(ll j=0;j<ci[i]/2;j++){
                    amount+=a[i][j];
                }
            }
            else{
                ll moresum=0;
                for(ll j=0;j<=ci[i]/2;j++){
                    moresum+=a[i][j];
                }
                v.push_back(make_pair(i,moresum));
            }
        }
        sort(v.begin(),v.end(),comp);
        ll l=v.size();
        if(l%2==0){
            for(ll i=0;i<l;i++){
                if(i<l/2)
                    amount+=v[i].second;
                else
                    amount+=v[i].second-a[v[i].first][ci[v[i].first]/2];
            }
        }
        else{
            for(ll i=0;i<l;i++){
                if(i<=l/2)
                    amount+=v[i].second;
                else
                    amount+=v[i].second-a[v[i].first][ci[v[i].first]/2];
            }
        }
        cout<<amount<<endl;
    }
    return 0;
}