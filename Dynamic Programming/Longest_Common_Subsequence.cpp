// given 2 strings find the longest common subsequence in the them
#include<bits/stdc++.h>
using namespace std;

//recursive approach
int LCS(char x[], char y[], int i, int j){

    int xlen= strlen(x);
    int ylen= strlen(y);
    if(i>=xlen || j>=ylen) return 0;

    if(x[i]==y[j]) return 1+LCS(x, y, i+1, j+1);
    else return max(LCS(x, y, i+1, j) , LCS(x, y, i, j+1));
}

// using bottom up dp
int LCSdp(char x[], char y[]){
    int m = strlen(x);
    int n = strlen(y);
    int dp[100][100]={0};

    for(int i=0;i<=n;i++) dp[0][i]=0;
    for(int j=0;j<=m;j++) dp[j][0]=0;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main(){
    char x[100], y[100];
    cin>>x>>y;
    
    cout<<LCSdp(x,y);
    return 0;
}