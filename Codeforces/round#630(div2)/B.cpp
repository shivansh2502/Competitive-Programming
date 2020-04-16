#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long


void primeFactors(ll n, map<ll, ll> &um){  
    if(n%2==0){
        um[2]++;
    }
    while (n % 2 == 0){  
        n = n/2;  
    }  
  
    for (ll i = 3; i <= sqrt(n); i = i + 2){
        if(n%i==0) um[i]++;
        while (n % i == 0){    
            n = n/i;  
        }  
    }  
 
    if (n > 2)  
        um[n]++; 
}  


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll color[n];
        ll currentcolor=1;
        for(ll i=0;i<n;i++){
            color[i]=0;
        }
        map<ll, ll> um;
        for(ll i=0;i<n;i++){
            primeFactors(a[i], um);
        }

        
        for(auto j:um){
            bool colorused=false;
            for(ll i=0;i<n;i++){
                if(color[i]==0 && a[i]%j.first==0){
                    color[i]= currentcolor;
                    colorused=true;
                }
            }
            if(colorused) currentcolor++;
        }
        
        cout<<currentcolor-1<<"\n";
        for(ll i=0;i<n;i++){
            cout<<color[i]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
