#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w, h, r;
    cin>>w>>h>>r;
    int x[r];
    int y[r];
    set<int> xi;
    set<int> yi;
    for(int i=0;i<r;i++){
        cin>>x[i]>>y[i];
        xi.insert(x[i]);
        yi.insert(y[i]);
    }
    int n,m;
    for(int i=1;i<w;i++){
        if(w%i==0){
            if(xi.find(i)==xi.end()){
                n=i;
                break;
            }
        }
    }
    for(int i=1;i<h;i++){
        if(h%i==0){
            if(yi.find(i)==yi.end()){
                m=i;
                break;
            }
        }
    }
    cout<<n<<" "<<m<<" "<<0<<endl;
    
    return 0;
}
