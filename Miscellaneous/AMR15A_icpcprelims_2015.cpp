#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[1000]={0};
    int odd=0,even=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]%2==0?even++:odd++;
    }
    if(even>odd)
        cout<<"READY FOR BATTLE"<<endl;
    else
        cout<<"NOT READY"<<endl;
    return 0;
}