// find the minimum number of operations required to change a given string to desired string
// you can either insert a letter or delete a letter or replace it

#include<bits/stdc++.h>
using namespace std;

// using bottom-up dp or pure dp
int editDistance(string inp, string out){
    int m= inp.length();
    int n= out.length();
    int dp[100][100];

    for(int i=0;i<n;i++){
        dp[0][i]=i;
    }

    for(int i=0;i<m;i++){
        dp[i][0]=i;
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            int ans1, ans2, ans3;
            if(inp[i]==out[j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                ans1= 1 + dp[i-1][j-1];
                ans2= 1 + dp[i-1][j];
                ans3= 1+ dp[i][j-1];
                dp[i][j]= min(ans1, min(ans2, ans3));
            }
            cout<<setw(3)<<dp[i][j];
        }
        cout<<endl;
    }
    return dp[m-1][n-1];
}

int main(){
    string inp;
    string out;
    cin>>inp>>out;
    inp= " "+ inp;
    out= " "+ out;
    cout<<editDistance(inp, out);
    return 0;
}

