#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll t;
    cin>>t;

    while(t--){

        ll x1, k1;
        cin>>x1>>k1;

        if(k1==1){
            if(x1>1) cout<<1<<endl;
            else cout<<0<<endl;
        }
        else{
            bool flag1=false;
            ll countx=0;
            
            for(ll itt=2; itt<=sqrt(x1); itt++){
                if(x1%itt==0){
                    countx++;
                    x1/=itt;
                    itt=1;
                    if( countx == k1-1  &&  x1>1 ){
                        flag1=true;
                        break;
                    }
                }
            }


            if(flag1) cout<<1<<endl;
            else cout<<0<<endl;
            
        }
    }
    return 0;
}


