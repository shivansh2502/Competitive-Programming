#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll  t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll  count=0;
        
        vector<ll > v;

        for(ll  i=0;i<s.length()-2;i++){

            if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e'){
                count++;
                if(i-1>=0 && i-1<s.length()){
                    if(s[i-1]=='o'){
                        s[i+1]='a';
                        v.push_back(i+2);
                    }
                    else{
                        s[i]='a';
                        v.push_back(i+1);
                    }
                }
                else{
                    s[i]='a';
                    v.push_back(i+1);
                }
            }

            else if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o'){
                count++;
                if(i+3<s.length() && i+3>=0){
                    if(s[i+3]=='o'){
                        s[i+1]='a';
                        v.push_back(i+2);
                    }
                    else{
                        s[i+2]='a';
                        v.push_back(i+3);
                    }
                }
                else{
                    s[i+2]='a';
                    v.push_back(i+3);
                }
            }
        }
        cout<<count<<endl;
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}