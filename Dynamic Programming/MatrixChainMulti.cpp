#include<bits/stdc++.h>
using namespace std;


int brackets[1000][1000];

void printbrackets(int i, int j, char& name){

    if(i==j){
        cout<<name++;
        return;
    }

    cout<<"(";
    printbrackets(i, brackets[i][j], name);
    printbrackets(brackets[i][j]+1, j, name);
    cout<<")";
}

int mcm(int* a, int n){

    int dp[n-1][n-1];

    memset(dp, 0, sizeof(dp));

    for(int i=1;i<n-1;i++){
        for(int j=0, k=i; k<n-1 ; j++, k++){
            dp[j][k]= INT_MAX;
            for(int l=j;l<k;l++){
                int val= dp[j][l] + dp[l+1][k] + a[j]*a[l+1]*a[k+1];
                if(dp[j][k]>val){
                    dp[j][k]=dp[j][l] + dp[l+1][k] + a[j]*a[l+1]*a[k+1];
                    brackets[j][k]=l;

                }
            }
        }
    }

    char name= 'A';
    printbrackets(0, n-2, name);
    cout<<endl;
    return dp[0][n-2];
}

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<mcm(a, n)<<endl;
}