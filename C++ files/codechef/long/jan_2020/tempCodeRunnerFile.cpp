#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,q;
    cin>>n>>q;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll countinc=0;
        ll countdec=0;
        
        for(ll  i=l;i<=r-1;i++){
            if(i==r-1){
                if(a[i]>a[i-1]){
                    countinc++;
                }
                else if(a[i]<a[i-1]){
                    countdec++;
                }
            }
            else{
                if(a[i-1]<a[i] && a[i+1]<a[i]){
                    countinc++;
                    
                }
                else if(a[i-1]>a[i] && a[i+1]>a[i]){
                    countdec++;
                }
            }
        }
        if(countdec==countinc){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}