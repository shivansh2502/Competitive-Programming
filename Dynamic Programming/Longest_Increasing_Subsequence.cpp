// given an array of elements find the length of the longest increasing subsequence
#include<bits/stdc++.h>
using namespace std;

int LIS(int a[], int n){
    int dp[100];
    for(int i=0;i<n;i++) dp[i]=1;

    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<=a[i]){
                dp[i]=max(dp[i], 1+dp[j]);
            }
        }
        ans= max(ans, dp[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<LIS(a,n);
    return 0;
}