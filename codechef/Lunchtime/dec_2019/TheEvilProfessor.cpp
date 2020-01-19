#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        string a;
        cin>>a;
        string s=a;
        ll ans=0;
        for(ll i=0;i<s.length();i++){
            for(ll j=i;j<s.length();j++){
                for(ll k=i;k<=j;k++){
                    if(s[k]=='0'){
                        s[k]='1';
                    }
                    else if(s[k]=='1'){
                        s[k]='0';
                    }
                }
                ll count=0;
                for(ll k=0;k<s.length()-1;k++){
                    if(s[k]==s[k+1]){
                        count++;
                    }
                }
                ans+=count;
                // cout<<count<<endl;
                // cout<<s<<endl;
                s=a;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}