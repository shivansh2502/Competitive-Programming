#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        if(__gcd(n,k)!=1 || __gcd(m,k)!=1){
            cout<<-1<<endl;
        }
        else{
            cout<<n*m<<endl;
        }
    }
    return 0;
}