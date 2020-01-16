#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int pens;
        if(a%c!=0){
            pens=a/c+1;
        }
        else{
            pens=a/c;
        }
        int pencils;
        if(b%d!=0){
            pencils=b/d+1;
        }
        else{
            pencils=b/d;
        }
        if(pens+pencils>k){
            cout<<-1<<endl;
        }
        else{
            cout<<pens<<" "<<pencils<<endl;
        }
    }
    return 0;
}