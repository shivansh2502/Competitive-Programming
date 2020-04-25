// given a grid of numbers find the minimum cost of going from one end to another
// cost is the sum of numbers from one end to another through the grid

#include<bits/stdc++.h>
using namespace std;


//using bottom up dp
int dp[100][100]={};
int minCostofgrid(int grid[][100], int m ,int n){

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


//print all possible paths with minimum cost
set<string> printPath(int grid[][100], int x, int y){
    set<string> s;
    if(x==0 && y==0){
        s.insert(""); 
        return s;
    }
    else if(x==0 || y==0){
        if(y==0){
            set<string> tmp= printPath(grid, x-1, y);
            for(auto i:tmp) s.insert(to_string(grid[x-1][y]) + i);
        }
        if(x==0){
            set<string> tmp= printPath(grid, x, y-1);
            for(auto i:tmp) s.insert(to_string(grid[x][y-1]) + i);
        }
    }
    else{
        if(dp[x-1][y] < dp[x][y-1]){
            set<string> tmp= printPath(grid, x-1, y);
            for(auto i:tmp) s.insert(to_string(grid[x-1][y])+ i);
        }
        else if(dp[x-1][y] > dp[x][y-1]){
            set<string> tmp= printPath(grid, x, y-1);
            for(auto i:tmp) s.insert(to_string(grid[x][y-1]) + i);
        }
        else{
            set<string> tmp1= printPath(grid, x, y-1);
            for(auto i:tmp1) s.insert(to_string(grid[x][y-1]) + i);

            set<string> tmp2= printPath(grid, x-1, y);
            for(auto i:tmp2) s.insert(to_string(grid[x-1][y]) + i);
        }
    }
    return s;
}


int main(){
    int grid[100][100]={
        {1,2,3},
        {3,8,2},
        {2,2,3}
    };
    cout<<minCostofgrid(grid,3,3)<<endl;
    set<string> s= printPath(grid, 2, 2);
    
    for(auto i:s){
        cout<<to_string(grid[2][2]);
        cout<<i<<endl;
    }

    return 0;
}