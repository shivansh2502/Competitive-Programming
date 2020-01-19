// given a grid of numbers find the minimum cost of going from one end to another
// cost is the sum of numbers from one end to another through the grid

#include<bits/stdc++.h>
using namespace std;


//using bottom up dp
int minCostofgrid(int grid[][100], int m ,int n){
    int dp[100][100]={};

    dp[0][0]=grid[0][0];

    for(int i=1;i<n;i++) dp[0][i]=dp[0][i-1]+grid[0][i];
    for(int i=1;i<m;i++) dp[i][0]= dp[i-1][0]+ grid[i][0];

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]= min( dp[i-1][j], dp[i][j-1]) + grid[i][j]; 
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<< setw(3)<<dp[i][j];
        }
        cout<<endl;
    }
    return dp[m-1][n-1];
}

int main(){
    int grid[100][100]={
        {1,2,3},
        {4,8,2},
        {1,5,3}
    };
    cout<<minCostofgrid(grid,3,3)<<endl;
    return 0;
}