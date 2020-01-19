#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// ll formula(ll  *f, ll  i){

//     if(f[i]!=-1){
//         return f[i];
//     }
//     int x=(i/2) + formula(f, i/2);
//     cout<<x<<endl;
//     return x;
// }

void fnc(ll y, vector<ll> &v){
    ll  f[100000]={-1};
    for(ll  i=0;i<100000;i++){
        if(i==0){
            f[i]=0;
        }
        else if(i%2!=0){
            f[i]=i*(i-1)/2;
        }
        else if(i%2==0){
            f[i]=i/2+f[i/2];
        }
        if(f[i]==y){
            v.push_back(i);
        }
        else if(f[i]>2*y){
            break;
        }
    }
    return;
}

int main(){
    ll  y;
    cin>>y;
    vector<ll> v;
    fnc(y, v);
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}