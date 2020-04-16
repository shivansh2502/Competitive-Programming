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
    if((s[s.length()-1]-'0')%2==0){
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
    }
    
    return 0;
}
