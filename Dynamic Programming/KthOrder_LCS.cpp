// given two strings find the longest common subsequence given the power to change any k alphabets from any 1 of them

#include<bits/stdc++.h>
using namespace std;

int dp[2005][2005][8];

//using memoization

int KthOrder_LCS(int i, int j, int k, char x[], char y[]){
    int m=strlen(x);
    int n=strlen(y);
    if(i==m || j==n) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(x[i]==y[j]){
        dp[i][j][k]= 1+KthOrder_LCS(i+1, j+1, k, x, y);
    }
    else{
        if(k>0){
            dp[i][j][k]= 1+ KthOrder_LCS(i+1, j+1, k-1, x, y);
        }
        dp[i][j][k]= max(dp[i][j][k], KthOrder_LCS(i+1, j, k, x, y));
        dp[i][j][k]= max(dp[i][j][k], KthOrder_LCS(i, j+1, k, x, y));
    }
    return dp[i][j][k];
}

int main(){
    memset(dp, -1, sizeof(dp));
    char x[100], y[100];
    cin>>x>>y;
    int k;
    cin>>k;
    cout<<KthOrder_LCS(0 , 0, k, x, y);
    return 0;
}