//given a number u can either divide it by 3 or by 2 or do -1
//find the minimum no. of steps required to reduce the number


#include<bits/stdc++.h>
using namespace std;

//recursive solution
int minStepsto1(int n){
    if(n==1) return 0;

    int q1=INT_MAX,q2=INT_MAX,q3=INT_MAX;
    if(n%3==0) q1=1+minStepsto1(n/3);
    if(n%2==0) q2=1+minStepsto1(n/2);
    q3=1+minStepsto1(n-1);
    
    return min(q1, min(q2,q3));
}

// top down dp approach(Memoization)
int memo[1000];
int minStepsto1memo(int n){
    if(n==1) return 0;
    if(memo[n]!=-1) return memo[n];

    int q1=INT_MAX;
    int q2=INT_MAX;
    int q3=INT_MAX;
    if(n%3==0) q1=1+minStepsto1memo(n/3);
    if(n%2==0) q2= 1+minStepsto1memo(n/2);
    q3= 1+ minStepsto1memo(n-1);

    memo[n]=min(q1,min(q2,q3));

    return memo[n];
}

// using bottom up dp (pure dp)
int minStepsto1dp(int n){
    int dp[n+1];
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int q1=INT_MAX;
        int q2=INT_MAX;
        int q3=INT_MAX;
        if(i%3==0) q1= 1+ dp[i/3];
        if(i%2==0) q2= 1+ dp[i/2];
        q3=1+dp[i-1];
        dp[i]=min(q1, min(q2,q3));
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    memset(memo, -1, sizeof(memo));
    cout<<minStepsto1dp(n)<<endl;
    return 0;
}