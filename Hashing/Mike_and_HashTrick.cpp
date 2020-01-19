#include<bits/stdc++.h>
using namespace std;
map<int,int> m;

bool compare(int a, int b){
    return m[a]<m[b];
}

void hash_array(int a[], int n){
    vector <int> v;
    for(int i=0;i<n;i++){
        if(m.count(a[i])==1){
            m[a[i]]=i;
        }
        else{
            m[a[i]]=i;
            v.push_back(a[i]);
        }
    }
    sort(v.begin(), v.end(), compare);
    for(auto i:v){
        cout<<i<<" ";
    }
    return;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    hash_array(a,n);
    return 0;
}