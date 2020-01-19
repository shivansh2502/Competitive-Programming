#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,y,k;
        cin>>x>>y>>k;
        ll sum=x+y;
        ll div=sum/k;
        if(div%2==0){
            cout<<"Chef"<<endl;
        }
        else{
            cout<<"Paja"<<endl;
        }
    }
    return 0;
}