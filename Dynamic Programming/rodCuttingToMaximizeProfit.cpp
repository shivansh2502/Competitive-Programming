// given a rod and the cost of rods cut from the original length find the max profit 
#include<bits/stdc++.h>
using namespace std;

// using recursive approach
int maxProfitearned(int a[], int n){
    if(n==0) return 0;

    int maxProfit=0;
    for(int i=1;i<=n;i++){
        int profit= a[i] + maxProfitearned(a, n-i); 
        maxProfit= max(profit, maxProfit); 
    }

    return maxProfit;
}


//using topdown dp or memoization
int memo[1000];
int maxProfitearnedmemo(int a[], int n){
    if(n==0) return 0;

    if(memo[n]!=-1) return memo[n];

    int maxProfit=0;
    for(int i=1;i<=n;i++){
        int profit= a[i] + maxProfitearnedmemo(a, n-i); 
        maxProfit= max(profit, maxProfit); 
    }
    memo[n]=maxProfit;
    return memo[n];
}

// using bottom up dp or pure dp
int maxProfitearneddp(int a[], int n){
    int dp[1000]={0};
    
    for(int i=1;i<=n;i++){
       for(int j=1;j<=i;j++){
           dp[i]= max(dp[i],a[j]+ dp[i-j]);
       }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    memset(memo, -1, sizeof(memo));
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    cout<<maxProfitearneddp(a, n);
    return 0;
}