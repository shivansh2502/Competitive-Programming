#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    ll a[129];
    a[0]=a[1]=0;
    for(ll i=2;i<=128;i++){
        int x=a[i-1];
        int diff=-1;
        for(int j=0;j<i-1;j++){
            if(a[j]==x){
                diff=j;
            }
        }
        if(diff==-1){
            a[i]=0;
        }
        else{
            a[i]=i-1-diff;
        }
    }
    for(int i=0;i<50;i++){
        cout<<a[i]<<" ";
    }

    // while(t--){
    //     int n;
    //     cin>>n;
    //     int count=0;
    //     for(int i=0;i<=n-1;i++){
    //         if(a[i]==a[n-1]){
    //             count++;
    //         }
    //     }
    //     cout<<count<<endl;
    // }

    return 0;
}