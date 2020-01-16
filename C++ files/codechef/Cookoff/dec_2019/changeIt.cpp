#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        unordered_map<int, int> um;
        for(int i=0;i<n;i++){
            cin>>a[i];
            um[a[i]]++;
        }
        int m=0;
        for(auto i:um){
            m=max(m, i.second);
        }
        cout<<n-m<<endl;

    }
    return 0;
}