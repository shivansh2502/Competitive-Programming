#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int b[n];
        unordered_map<int, int> um;
        for(int i=0;i<n;i++){
            cin>>a[i];
            
        }
        unordered_map<int, int> common;
        for(int i=0;i<n;i++){
            cin>>b[i];
            int c= a[0]^b[i];
            int d= a[1]^b[i];
            common[c]++;
            common[d]++;
            um[b[i]]++;
        }
        set<int> s;
        for(auto i:common){
            if(i.second==2){
                s.insert(i.first);
            }
        }
        int xr=0;
        for(auto j:s){
            int count=0;
            for(int i=2;i<n;i++){
                int d= a[i]^j;
                if(um[d]<=0){
                    break;
                }
                else{
                    count++;
                    um[d]--;
                }
            }
            if(count==n-3){
                xr=j;
                break;
            }
        } 
        if(xr==0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<n;i++){
                cout<<a[i]^xr<<" ";
            }
            cout<<endl;
        }

    }
    
    return 0;
}
