#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x=1;
        int y=2;
        int ans=0;
        for(int i=0;i<20;i+=2){
            if((n&x)>0 && (n&y)==0){
                ans+=y;
            }
            else if((n&x)==0 && (n&y)>0){
                ans+=x;
            }
            else if((n&x)>0 && (n&y)>0){
                ans+=x;
                ans+=y;
            }
            x=x<<2;
            y=y<<2;
        }
       
        cout<<ans<<endl;
    }
}