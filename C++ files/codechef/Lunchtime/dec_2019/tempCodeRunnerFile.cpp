#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,m;
        cin>>a>>m;
        int n=m/a;
        vector<int> v;
        while(n>0){
            int diff= m- a*n;
            if(diff==0){
                continue;
            }
            if(n%diff==0){
                v.push_back(n);
            }
            n--;
        }
        if(v.size()==0){
            cout<<0<<endl;
            cout<<endl;
        }
        else{
            for(auto i : v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}