#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long


// using recursion
bool interleaving( string s1, string s2, string s3, int i, int j, int k){

    if(s1.length()+ s2.length() != s3.length()) return false;

    if(i == s1.length()) return s2.substr(j)==s3.substr(k);
    
    if(j == s2.length()) return s1.substr(i)==s3.substr(k);

    if((s1[i] == s3[k] && interleaving(s1, s2, s3, i+1, j, k+1)) || (s2[j]== s3[k] && interleaving(s1, s2, s3, i, j+1, k+1))){
        return true;
    }
    else return false;
}

// using memoization(top down dp)
bool dp[100][100];
bool interleavingmemo(string s1, string s2, string s3,  int i, int j){

    if(s1.length() + s2.length()!= s3.length()) return false;
    dp[0][0]=1;
    for(int i=1;i<=s1.length();i++){
        dp[i][0]= dp[i-1][0] && s1[i-1]== s3[i-1]; 
    }
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            dp[i][j]= ((dp[i-1][j] && s1[i]==s3[i+j]) || (dp[i][j-1] && s2[j]= s3[i+j]));
        }
    }

}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    memset(dp, 0, sizeof(dp));
    cout<<interleaving(s1, s2, s3, 0, 0, 0)<<endl;
    
    return 0;
}
