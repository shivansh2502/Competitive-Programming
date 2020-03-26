#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll1;

int main(){

    ll1 test;
    cin>>test;

    while(test--){

        ll1 num, qu;
        cin>>num>>qu;

        ll1 a[num+1]={0};

        for(ll1 ittr=1;ittr<=num;ittr++){
             
            cin>>a[ittr];

        }
       
        while(qu--){

            ll1 countans=0;

            ll1 x10, x20, y1;

            cin>>x10>>x20>>y1;

            
            for(ll1 ittr=x10;ittr<x20;ittr++){

                if((a[ittr]>=y1 && a[ittr+1]<=y1) || (a[ittr]<=y1 && a[ittr+1]>=y1)){

                    countans++;

                }

            }

            cout<<countans<<endl;

        }

    }
    return 0;
}
