#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int x= a^b;
        int count= __builtin_popcount(x);
        cout<<count<<endl;
    }
    return 0;
}