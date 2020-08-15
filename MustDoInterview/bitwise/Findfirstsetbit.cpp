#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){

        // brute force approach
        int n;
        cin>>n;
        /*
        int x=1;
        int pos=1;
        bool flag=false;
        while(x<=n){
            if(n&x){
                cout<<pos<<endl;
                flag=true;
                break;
            }
            x=x<<1;
            pos++;
        }

        if(!flag) cout<<0<<endl;*/

        // best approach
        if(n!=0) cout<<log2(n & -n)+1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}