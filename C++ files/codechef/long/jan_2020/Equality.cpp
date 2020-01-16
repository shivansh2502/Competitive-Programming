#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q;
    cin>>n>>q;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }

    ll  cd=0;
    ll  ci=0;
    vector<pair<ll , ll >> v;
    bool inc=false;
    v.push_back(make_pair(0,0));
    for(ll  i=1;i<n;i++){
        if(i==1){
            if(a[i-1]<a[i]){
                ci++;
                inc=true;
            }
            else if(a[i-1]>a[i]) {
                cd++;
                inc=false;
            }
        }
        else{
            if(a[i-1]<a[i] && inc==false){
                ci++;
                inc=true;
            }
            else if(a[i-1]>a[i] && inc==true){
                cd++;
                inc=false;
            }
        }
        v.push_back(make_pair(ci, cd));
        // cout<<ci<<" "<<cd<<endl;
    }

    while(q--){
        ll l,r;
        cin>>l>>r;
        ll countinc=0;
        ll countdec=0;
        if(l==1){
            countinc= v[r-1].first-v[l-1].first;
            countdec= v[r-1].second-v[l-1].second;
        }
        else{
            if(v[l-1].first== v[l].first &&
                v[l-1].second== v[l].second
            ){

                if(a[l-1] < a[l]){
                    countinc= v[r-1].first - v[l-1].first+1;
                    countdec= v[r-1].second - v[l-1].second;
                }
                else if(a[l-1] > a[l]){
                    countinc= v[r-1].first-v[l-1].first;
                    countdec= v[r-1].second-v[l-1].second+1;
                }
            }
            else{
                countinc= v[r-1].first-v[l-1].first;
                countdec= v[r-1].second-v[l-1].second;
            }
        }
        //cout<<countinc<<" "<<countdec<<endl;
        if(countdec==countinc){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}