#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(n==m){
            cout<<-1<<endl;
            continue;
        } 

        //brute force solution
        /*
        int x=1;
        int pos=1;
        while(!((n&x)^(m&x))){
            pos++;
            x=x<<1;
        }
        cout<<pos<<endl;
        */
        int x= n^m;
        cout<<log2(x & -x) + 1<<endl;
    }
    return 0;
}