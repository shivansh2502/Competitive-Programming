#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll sum=0;
        for(ll i=1;i<=n-1;i++){
            sum+=i;
        }
        ll fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
        }
        cout<<fact*sum<<endl;
    }
    return 0;
}