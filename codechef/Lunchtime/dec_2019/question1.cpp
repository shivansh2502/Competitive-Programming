#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string ans="";
        int length=1;
        // if(s.length()==1){
        //     ans+=s[0];
        //     ans+='1';
        // }
        int itr=1;
        for(itr;itr<s.length();itr++){
            if(s[itr-1]==s[itr]){
                length++;
            }
            else{
                string str= to_string(length);
                ans+=s[itr-1];
                ans+=str;
                length=1;

            }
        }
        string str= to_string(length);
        ans+=s[itr-1];
        ans+=str;
        // for(int i=0;i<ans.length();i++){
        //     cout<<ans[i];
        // }
        // cout<<endl;
        if(ans.length()<s.length()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}