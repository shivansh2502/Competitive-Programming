#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<int,int> um;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(um.count(x)==1){
            um[x]++;
        }
        else{
            um[x]=1;
        }
    }
    int max=0;
    int maxv=0;
    for(auto i:um){
        if(max<=i.second){
            max=i.second;
            maxv=i.first;
        }
    }
    cout<<maxv<<endl;

    return 0;
}