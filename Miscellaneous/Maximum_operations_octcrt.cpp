#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll togglebit(ll n) 
{ 
    if (n == 0) 
        return 1; 
    ll i = n; 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    return i ^ n; 
}
ll XNOR(ll num1, ll num2) 
{
    if (num1 < num2) 
        swap(num1, num2);  
    num1 = togglebit(num1); 
    
    return num1 ^ num2; 
} 

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        ll c=a^b;
        ll d=XNOR(a,b);
        if(n%3==0){
            cout<<max(c,d)<<endl;
        }
        else if(n%3==1){
            cout<<a<<endl;
        }
        else if(n%3==2){
            cout<<b<<endl;
        }
    }
    
    return 0;
}