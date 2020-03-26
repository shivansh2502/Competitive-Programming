#include<bits/stdc++.h>
using namespace std;
#define ll long long


// using top down dp or memoization
int dp[100][100];
int FormPalindrome(string s, int f, int l){

    if(dp[f][l]!=-1) return dp[f][l];
    if(f>l) return INT_MAX;
    if(f==l) return 0;
    if(f==l-1) return (s[f]==s[l])? 0: 1;
    
    if(s[f]==s[l]) dp[f][l]= FormPalindrome(s, f+1, l-1);
    
    else  dp[f][l]= min(FormPalindrome(s, f+1, l), FormPalindrome(s, f, l-1))+1;
    
    return dp[f][l];
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    memset(dp, -1, sizeof(dp));
	    int length= s.length()-1;
	    cout<<FormPalindrome(s, 0, length)<<endl;
	}
	return 0;
}