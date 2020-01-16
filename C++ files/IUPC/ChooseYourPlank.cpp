#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll  n;
    cin>>n;
    ll  a[n];
    for(ll  i=0;i<n;i++){
        cin>>a[i];
    }
    ll  last=a[n-1];
    ll  count=1;
    for(ll  i=n-2;i>=0;i--){
        if(a[i]==last){
            count++;
        }
        else{
            break;
        }
    }
    if(count%2==0){
        cout<<"Customer-B"<<endl;
    }
    else{
        cout<<"Customer-A"<<endl;
    }
    return 0;
}