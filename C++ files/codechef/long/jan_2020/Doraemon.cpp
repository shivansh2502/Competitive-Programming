#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll test;
    cin>>test;
    while(test--){


        ll n1,m1;
        cin>>n1>>m1;
        ll arr[n1][m1];

        ll ans=n1*m1;

        for(ll i=0;i<n1;i++){
            for(ll j=0;j<m1;j++){
                cin>>arr[i][j];
            }
        }


        for(ll it=0;it<n1;it++){

            for(ll jt=0 ;jt<m1;jt++){

                ll itt=it;

                ll jtt=jt;

                ll x=1;

                while((itt+x)>=0 && (itt+x)<n1 && (itt-x)>=0 && (itt-x)<n1 && (jtt-x)>=0 && (jtt-x)<m1 && (jtt+x)>=0 && (jtt+x)<m1)
                {
                    if(arr[itt-x][jtt]==arr[itt+x][jtt] &&  arr[itt][jtt-x]==arr[itt][jtt+x]){

                        ans++;
                    }
                    else{

                        break;
                    }

                    x++;
                }
            }
        }
        cout<<ans<<"\n";
    }


    return 0;
}