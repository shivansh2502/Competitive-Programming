#include<bits/stdc++.h>
using namespace std;
#define ll long long

class comp{
    public:
        bool operator()(pair<ll, ll> p,pair<ll, ll> q){
            return p.first>q.first;
        }
};


int main(){
    ll k,n;
    cin>>k>>n;
    ll a[k][n];
    for(ll i=0;i<k;i++){
        for(ll j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, comp> pq;
    vector<ll> ans;
    for(ll i=0;i<k;i++){
        pq.push(make_pair(a[i][0],i));
    }
    ll size[k]={0};
    while(pq.top().first!=INT_MAX){
        ans.push_back(pq.top().first);
        ll i=pq.top().second;
        size[i]++;
        if(size[i]<n){
            pq.push(make_pair(a[i][size[i]],i));
        }
        else{
            pq.push(make_pair(INT_MAX,i));
        }
        pq.pop();
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}