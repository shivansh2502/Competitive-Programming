#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll  n,m;
        cin>>n>>m;
        ll  a[m][n];
        ll  avg[m];
        ll  pass[n]={0};
        for(ll  i=0;i<m;i++){
            ll  sum=0;
            for(ll  j=0;j<n;j++){
                cin>>a[i][j];
                sum+=a[i][j];
            }
            avg[i]=sum/n;
        }
        for(ll  i=0;i<m;i++){
            for(ll  j=0;j<n;j++){
                if(a[i][j]>avg[i] && pass[j]==0){
                    pass[j]=1;
                }
            }
        }
        ll  count=0;
        for(ll  i=0;i<n;i++){
            if(pass[i]==1){
                count++;
            }
        }
        cout<<count<<endl;

    }
    return 0;
}