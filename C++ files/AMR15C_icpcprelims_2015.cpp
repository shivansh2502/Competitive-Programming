#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int x=0;
        for(int i=1;i<=n;i++){
            if((i+k<=n && i+k>=1) || (i-k>=1 && i-k<=n )){
                x++;
            }
        }
        if(x==n){
            for(int i=k+1;i<=n;i++){
                cout<<i<<" ";
            }
            for(int i=1;i<=k;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}