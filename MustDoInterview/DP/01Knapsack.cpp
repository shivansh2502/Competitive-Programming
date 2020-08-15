// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0/?track=md-dp&batchId=144
#include<bits/stdc++.h>
using namespace std;


// recursive approach 
int knapsackrec(int w, int* value, int* weight, int n){
    
    if(n==0 || w==0) return 0;

    if(weight[n-1]> w){
        return knapsackrec(w, value, weight, n-1);
    }
    else{
        return max(value[n-1]+ knapsackrec(w-weight[n-1], value, weight, n-1), knapsackrec(w, value, weight, n-1));
    }
}


// bottom up dp 
int dp[1001][1001];
int knapsackdp(int w, int* value, int* weight, int n){
    
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=w;i++) dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(weight[i-1]<=j){
                dp[i][j]= max(value[i-1]+ dp[i-1][j-weight[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
	    cin>>n;
	    int w;
	    cin>>w;
	    int value[n];
	    for(int i=0;i<n;i++) cin>>value[i];
	    int weight[n];
	    for(int i=0;i<n;i++) cin>>weight[i];

        int ans=knapsackdp(w, value, weight, n);
        cout<<ans<<endl;
    }

    
    return 0;
}


