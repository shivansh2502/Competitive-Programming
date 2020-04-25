// Question 2 on DIGIT DP
// HackerEarth
// https://www.hackerearth.com/problem/algorithm/benny-and-the-broken-odometer/
#include<bits/stdc++.h>
using namespace std;
#define int long long

void sm25official(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


//position tight and flag as parameters of dp array
int dp[11][2][2];

int func(string s, int pos=0, int tight=1, int flag=0){
    if(pos==s.length()){
        if(flag==1) return 1;
        else return 0;
    }
    else if(dp[pos][tight][flag]!=-1) return dp[pos][tight][flag];

    else if(tight==1){
        int res=0;
        for(int i=0;i<= s[pos]-'0';i++){
            int flg= flag;
            if(i==3) flg=1;
            if(i== s[pos]-'0') res+=func(s, pos+1, 1, flg);
            else res+=func(s, pos+1, 0, flg);
        }
        return dp[pos][tight][flag]=res;
    }
    else if(tight==0){
        int res=0;
        for(int i=0;i<=9;i++){
            int flg= flag;
            if(i==3) flg=1;
            res+=func(s, pos+1, 0, flg);
        }
        return dp[pos][tight][flag]=res;
    }

}

int32_t main(){
    sm25official();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a= to_string(n);
        memset(dp, -1, sizeof(dp));
        cout<<n- func(a)<<endl;
    }
    return 0;
}