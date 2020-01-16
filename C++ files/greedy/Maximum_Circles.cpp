#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int main(){
    int n;
    cin>>n;
    int c[n];
    int r[n];
    for(int i=0;i<n;i++){
        cin>>c[i]>>r[i];
    }
    vector<pair<int,int>> time; 
    for(int i=0;i<n;i++){
        time.push_back(make_pair(c[i]-r[i],c[i]+r[i]));
    }
    sort(time.begin(),time.end(),comp);
    // for(int i=0;i<n;i++){
    //     cout<<time[i].second<<" ";
    // }
    int count=0;
    int x=time[0].first;
    for(int i=0;i<n;i++){
        if(x>time[i].first){
            count++;
        }
        else{
            x=time[i].second;
        }
    }
    cout<<count<<endl;
    return 0;
}