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

string s;
void findSubstring(int dp[][1001], int m, int n, char x[], int l){
    if(m==0 || n==0){
        if(s.length()==l){
            cout<<s<<endl;
            s.clear();
        }
        s.clear();
        return;
    }

    if(dp[m-1][n]==dp[m][n-1] && dp[m-1][n]!= dp[m][n]){
        s= x[m-1] + s; 
        findSubstring(dp, m-1, n-1, x, l);
    }

    if(dp[m-1][n]==dp[m][n]){
        findSubstring(dp, m-1, n, x, l);
    }
    else if(dp[m][n-1]==dp[m][n]){
        findSubstring(dp, m, n-1, x, l);
    }
    
}

// using bottom up dp
int LCSdp(char x[], char y[]){
    int m = strlen(x);
    int n = strlen(y);
    int dp[m+1][1001]={0};

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
    // findSubstring(dp, m, n, x, dp[m][n]);
    // return;
    return dp[m][n];
}



int main(){
    char x[1000], y[1000];
    cin>>x>>y;
    cout<<LCSdp(x,y)<<endl;
    // LCSdp(x,y);
    return 0;
}