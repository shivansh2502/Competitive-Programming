#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[1003];
    int b[1003];
    unordered_map<int, int> um;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(um.count(a[i])==1){
            um[a[i]]++;
        }
        else{
            um[a[i]]=1;
        }
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(um.count(b[i])==1 && um[b[i]]>=1){
            v.push_back(b[i]);
            um[b[i]]--;
        }
    }
    sort(v.begin(),v.end());
    cout<<"[";
    for(int i=0;i<v.size();i++){
        if(i==v.size()-1)
            cout<<v[i];
        else
            cout<<v[i]<<", ";
    }
    cout<<"]";

    return 0;
}