#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll changes[n/k];

        for(ll j=0;j<n/k;j++){
            vector<char> v(k);
            for(ll i=j*k ;i<(j+(1/2))*k;i++){
                v[i%k]=v[((j+1)*k-i-1)%k]= s[i] ;
                if(s[((j+1)*k -i-1)]!= s[i]){
                    changes[j]++;
                }
            }
            for(int i=0;i<k;i++){
                cout<<v[i];
            }
            cout<<endl;
            // for(ll i=0;i<n;i++){
            //     if(s[i]!= pattern[i%k] ){
            //         changes[j]++;
            //     }
            // }
        }


        ll minchanges=INT_MAX;
        for(ll i=0;i<n/k;i++){
            cout<<changes[i]<<endl;
            minchanges= min(changes[i], minchanges);
        }
        cout<<minchanges<<"\n";

    }
    
    return 0;
}
