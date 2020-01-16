#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll count[10]={0};
        while(n--){
            string s;
            cin>>s;
            for(int i=0;i<s.length();i++){
                if(s[i]=='1'){
                    count[i]++;
                }
            }
        }
        int finalans=0;
        for(int i=0;i<10;i++){
            if(count[i]%2!=0){
                finalans++;
            }
        }
        cout<<finalans<<endl;
    }
    return 0;
}