//GONE - G-One Numbers
//SPOJ PROBLEM ON DIGIT-DP
//https://www.spoj.com/problems/GONE/
#include<bits/stdc++.h>
using namespace std;
#define int long long


void sm25official()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

bool checkprime(int sum){
    for(auto i:prime){
        if(i==sum) return 1;
    }
    return 0;
}

//declare dp array
//1st parameter is for digits in the number
//2nd is for max sum which can be attained
//3rd parameter is for tight which can either 0 or 1
int dp[10][100][2];

//the main work in digit dp is generate all the numbers as shown below and 
// is the condition is satisfied by the number made in the end

int g1(string n, int pos=0, int sum=0, int tight=1){
    if(pos== n.length()){
        if(checkprime(sum)) return 1;
        else return 0;
    }
    if(dp[pos][sum][tight]!=-1) return dp[pos][sum][tight];
    
    if(tight==1){
        int res=0;
        for(int i=0;i<=n[pos]-'0';i++){
            if(i==n[pos]-'0') res+=g1(n, pos+1, sum+i, 1);
            else res+=g1(n, pos+1, sum+i, 0);
        }
        dp[pos][sum][tight]= res;
        return res;
    }
    else{
        int res=0;
        for(int i=0;i<=9;i++){
            res+=g1(n, pos+1, sum+i, 0);
        }
        dp[pos][sum][tight]= res;
        return res;
    }
}

int32_t main(){
    sm25official();
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        l=l-1;
        string a= to_string(l);
        string b= to_string(r);
        memset(dp, -1, sizeof(dp));
        int ans1=g1(b);
        memset(dp, -1, sizeof(dp));
        int ans2= g1(a);
        cout<<ans1-ans2<<endl;
    }
    return 0;
}