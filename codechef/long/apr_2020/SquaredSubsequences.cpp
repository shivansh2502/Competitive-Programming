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

        ll n1;
        cin>>n1;

        vector<ll> vi(n1);

        ll sum1=0;
        map<ll, ll> mapint;

        for(ll itt=0; itt<n1; itt++){

            ll k1;
            cin>>k1;
            vi.push_back(k1);

            sum1+=__builtin_ctzll(k1);
            mapint[sum1]++;

        }


        map<ll, ll> sumint;

        ll subord=0;

        for(ll itt=0;itt<=sum1;itt++){

            if(mapint.count(itt)) subord+=mapint[itt];

            sumint[itt]=subord;
        }

        ll finalans=0;

        for(auto itt:mapint){

            if(itt.first==1){
                finalans+= itt.second*(itt.second-1)/2;
            }

            if(itt.first==0){
                finalans+= itt.second*(itt.second-1)/2;
                finalans+=itt.second;
            }

            if(itt.first>1){
                ll countint=sumint[itt.first-2];
                
                finalans+= itt.second;
                finalans+= itt.second* countint;
                finalans+= itt.second*(itt.second-1)/2;
            }

        }

        cout<<finalans<<endl;
    }

    return 0;
}


