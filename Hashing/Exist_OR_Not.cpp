#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[100005];
        unordered_map<int, int> um;
        for(int i=0;i<n;i++){
            cin>>a[i];
            um[a[i]]=i;
        }
        int q;
        cin>>q;
        while(q--){
            int x;
            cin>>x;
            if(um.count(x)==1){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}