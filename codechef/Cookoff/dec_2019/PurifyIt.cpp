#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while(t--){

        string s;
        cin>>s;

        ll biggest_bunch1=0;
        ll biggest_bunch0=0;
        ll count0=0, count1=0;
        ll total_count0=0;
        ll total_count1=0;

        for(unsigned ll i=0;i<s.length();i++){
            if(s[i]=='0'){
                count1=0;
                count0++;  
                biggest_bunch0=max(biggest_bunch0, count0);   
                total_count0++;
            }
            else if(s[i]=='1'){
                count0=0;
                count1++;
                biggest_bunch1=max(biggest_bunch1, count1);
                total_count1++;
            }
        }
        // cout<<"0->"<<biggest_bunch0<<endl;
        // cout<<"1->"<<biggest_bunch1<<endl;
        cout<< min(total_count0-biggest_bunch0, total_count1-biggest_bunch1)<<endl;
    }
    return 0;
}