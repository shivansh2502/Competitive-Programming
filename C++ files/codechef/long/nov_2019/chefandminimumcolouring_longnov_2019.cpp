#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(pair<ll,ll> vec1, pair<ll,ll> vec2){
    return vec1.first < vec2.first;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll m,n;
        cin>>n>>m;
        vector<pair<ll,ll>> vec;
        for(ll i=0;i<n;i++){
            ll value;
            cin>>value;
            vec.push_back(make_pair(value,i%m));
        }
        sort(vec.begin(),vec.end(),comp);
        // for(int i=0;i<n;i++){
        //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
        // }
        vector<ll> v;
        for(ll i=0;i<n;i++){
            unordered_set<ll> set;
            ll count=0;
            ll initial=i;
            ll final=i-1;
            ll j=i;
            while(count<m &&j<n){
                if(set.find(vec[j].second)==set.end()){
                    set.insert(vec[j].second);
                    count++;
                }

                final++;
                j++;
            }
            // for(auto i:set){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            // cout<<initial<<" "<<final<<endl;
            if(count==m){
                v.push_back(vec[final].first - vec[initial].first);
            }
        }
        ll minimum=INT_MAX;
        for( auto i=v.begin();i<v.end();i++){
            // cout<<*i<<endl;
            if(minimum>*i){
                minimum=*i;
            }
        }
        cout<<minimum<<endl;
    }
    return 0;
}