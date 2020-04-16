#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<s.length();i++){

        sum+=(s[i]-'A')+1;
        
    }
    cout<<sum;
    
    return 0;
}
