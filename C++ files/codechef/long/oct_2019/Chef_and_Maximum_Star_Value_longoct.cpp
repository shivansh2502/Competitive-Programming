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
        ll maxi=0;
        ll b[1000000]={0};
        for(ll i=0;i<n;i++){
            cin>>a[i];
            maxi=max(maxi,b[a[i]]);
            for(ll j=1;j<=sqrt(a[i]);j++){
                if(a[i]%j==0){
                    if(a[i]/j==j){
                        b[j]++;
                       
                    }
                    else{
                        b[j]++;
                        b[a[i]/j]++;
                    }
                }
            }
            
        }
        cout<<maxi<<endl;

    }
    return 0;
}