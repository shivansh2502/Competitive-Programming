#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    if(a[0]==0){
        cout<<-1<<endl;
        return 0;
    }

    int dp[n];
    for(int i=0;i<n;i++) dp[i]=INT_MAX;

    dp[0]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(j+a[j] >=i){
                dp[i]= min(dp[i], dp[j]);
            }
        }
        dp[i]++;
    }

    cout<<dp[n-1]<<endl;
    
    return 0;
}