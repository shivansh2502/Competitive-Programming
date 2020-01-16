#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    string s;
    cin >> s;

    ll  length = s.length();
    ll  ans = s.length();


    for(ll  j = 0; j < 26; j++){
        ll  lo = -1, gap = 0;
        for(ll  i = 0; i<length; i++){
            if(s[i] == 'a' + j){
                gap = max(gap, i - lo);
                lo = i;
            }
        }
        if(length - lo > gap){
            gap=length - lo;
        }
        if(ans>gap){
            ans=gap;
        }
    }

    cout <<ans<<endl;
    return 0;
}