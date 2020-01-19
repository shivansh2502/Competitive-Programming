#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(a>b){
            swap(a,b);
        }
        if(a==0){
            cout<<"N0"<<endl;
            continue;
        }
        bool flag=false;
        double d=(double)b/a;
        if(d<2){
            ll a1=a;
            ll b1=b;
            while(a1!=0 && b1!=0){
                a1=a1-2;
                b1=b1-1;
                if(a1>b1){
                    swap(a1,b1);
                }
                if(a1!=0){
                    double div=(double)b1/a1;
                    if(div==2){
                        cout<<"YES"<<endl;
                        flag=true;
                        break;
                    }
                    else if(div>2){
                        break;
                    }
                }
                if(a1==0 && b1==0){
                    cout<<"YES"<<endl;
                    flag=true;
                    break;
                }
            }
        }
        else if(d==2){
            cout<<"YES"<<endl;
            flag=true;
        }
        if(flag==false){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}