// given 1 cell u have to construct n cells with minimum cost
// given the cost of doubling x, cost of addition of 1 as y, cost of reduction of 1 as z
#include<bits/stdc++.h>
using namespace std;

int solveCellProblem(int n, int x, int y, int z){
    int dp[1000];
    dp[0]=dp[1]=0;
    for(int i=2;i<=n;i++){
        // even 
        if(i%2==0){
            dp[i]= min(dp[i/2]+x, dp[i-1]+y);
        }
        else{
            dp[i]= min(dp[i-1]+ y, dp[(i+1)/2]+x+z);
        }
    }
    return dp[n];
}

int main(){
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    cout<<solveCellProblem(n, x, y, z);
    return 0;
}