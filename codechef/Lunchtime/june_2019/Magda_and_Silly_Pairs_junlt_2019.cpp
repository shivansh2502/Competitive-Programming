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
        ll b[n];
        ll odda=0;
        ll oddb=0;
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%2!=0){
                odda++;
            }
            sum+=a[i]/2;
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            sum+=b[i]/2;
            if(b[i]%2!=0){
                oddb++;
            }
        }
        sum+=min(odda,oddb);
        cout<<sum<<endl;
    }
    return 0;
}