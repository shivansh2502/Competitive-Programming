// we can only sell the wines in the start and end
// the cost of selling a wine is the cost of wine * year in which it is being sold then find max profit

#include<bits/stdc++.h>
using namespace std;

// recursive approach
int maxProfitofwine(int a[], int s, int e, int years){
    if(s>e) return 0;

    int ans1= a[s]*years + maxProfitofwine(a, s+1, e, years+1);
    int ans2= a[e]*years + maxProfitofwine(a, s, e-1, years+1);
    return max(ans1, ans2);
}

//using memoization or top down dp
int memo[100][100];
int maxProfitofwinememo(int a[], int s, int e, int years){
    if(s>e) return 0;

    if(memo[s][e]!=-1) return memo[s][e];

    int ans1= a[s]*years + maxProfitofwinememo(a, s+1, e, years+1);
    int ans2= a[e]*years + maxProfitofwinememo(a, s, e-1, years+1);
    memo[s][e]=max(ans1, ans2);

    return memo[s][e];
}

// using bottom up of pure dp
int maxProfitofwinedp(int a[], int s, int e){
    int n=e-s+1;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][i]= n*a[i]; 
    }

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int lastind = i+len-1;
            dp[i][lastind]= max( a[i]*(n-len+1)+dp[i+1][lastind],
                            a[lastind]*(n-len+1) + dp[i][lastind-1] );
                            
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<setw(4)<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
    return dp[s][e];
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    memset(memo, -1, sizeof(memo));
    cout<<maxProfitofwinedp(a,0,n-1);
    // cout<<maxProfitofwinememo(a,0,n-1,1)<<endl;
    return 0;
}