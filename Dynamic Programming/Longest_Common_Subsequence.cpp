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


//print all LCS 
int dp[100][100]={0};
set<string> findSubseeq(int m, int n, char x[], char y[]){
    set<string> s;
    if(m==0 || n==0){
        s.insert("");
        return s;
    }

    if(x[m-1]== y[n-1]){
        set<string> temp=findSubseeq(m-1, n-1, x, y);
        for(auto i:temp) s.insert(i+ x[m-1]);
    }

    else{
        if(dp[m-1][n]==dp[m][n]){
            set<string> temp=findSubseeq(m-1, n, x, y);
            for(auto i:temp) s.insert(i);
        }
        if(dp[m][n-1]==dp[m][n]){
            set<string> temp=findSubseeq(m, n-1, x, y);
            for(auto i:temp) s.insert(i);
        }
    }
    return s;
}

// using bottom up dp
int LCSdp(char x[], char y[]){
    int m = strlen(x);
    int n = strlen(y);

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
    char x[1000], y[1000];
    cin>>x>>y;
    memset(dp, 0, sizeof(dp));
    cout<<LCSdp(x,y)<<endl;
    set<string> s= findSubseeq(strlen(x), strlen(y), x, y);
    for(auto i:s){
        cout<<i<<endl;
    }
    // LCSdp(x,y);
    return 0;
}