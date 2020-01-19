#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll maxsum=0;
        for(ll i=0;i<n-1;i++){
            for(ll j=i+1;j<n;j++){
                ll prod=a[i]*a[j];
                ll digisum=0;
                while(prod){
                    digisum+=prod%10;
                    prod/=10;
                }
                maxsum=max(maxsum,digisum);
            }
        }
        cout<<maxsum<<endl;
    }
    return 0;
}