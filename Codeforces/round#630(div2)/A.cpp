#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    
    ll t;
    cin>>t;
    while(t--){   
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        bool xflag=false;
    
        ll xmargin= x-a+b;
        if(xmargin==x && a!=0 && b!=0){
            if((xmargin>=x1 && xmargin<x2) || (xmargin>x1 && xmargin<=x2)){
                xflag=true;
            }
            else{
                cout<<"No"<<"\n";
                xflag=false;
            }
        }
        else{
            if((xmargin>=x1 && xmargin<=x2)){
                xflag=true;
            }
            else{
                cout<<"No"<<"\n";
                xflag=false;
            }
        }
        if(!xflag){
            continue;
        }
        bool yflag=false;
        ll ymargin= y-c+d;
        if(ymargin==y && c!=0 && d!=0){
            if((ymargin>=y1 && ymargin<y2) || (ymargin>y1 && ymargin<=y2)){
                yflag=true;
            }
            else{
                cout<<"No"<<"\n";
                yflag=false;
            }
        }
        else{
            if((ymargin>=y1 && ymargin<=y2)){
                yflag=true;
            }
            else{
                cout<<"No"<<"\n";
                yflag=false;
            }
        }
        if(yflag){
            cout<<"Yes"<<"\n";
        }
        else{
            continue;
        }
    }
    
    return 0;
}
