#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll1;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll1  test;
    cin>>test;

    while(test--)
    {

        ll1 number,m1;
        cin>>number>>m1;

        set<ll1> xtest;
        set<ll1> ytest;

        ll1 x0point1=0;

        ll1 y0point1=0;

        for(ll1 ittr=0;ittr<number;ittr++){

            ll1 ktest;
            cin>>ktest;

            if(ktest!=0) xtest.insert(ktest);
            else x0point1++;

        }
        for(ll1 ittr=0;ittr<m1;ittr++){

            ll1 q1;

            cin>>q1;

            if(q1!=0) ytest.insert(q1);

            else y0point1++;

        }

        ll1 count11=0;

        for(auto attr:xtest)
        {

            for(auto bttr:ytest)
            {

                if((bttr*bttr*-1)%attr==0)
                {

                    ll1 value= (bttr*bttr*-1)/attr;

                    if(xtest.find(value)!=xtest.end()) count11++;

                }
                if((attr*attr*-1)%bttr==0)
                {

                    ll1 value= (attr*attr*-1)/bttr;

                    if(ytest.find(value)!= ytest.end()) count11++;

                }  
            }
        }

        count11/=2;
        
        if(y0point1 > 0) count11+=(m1-1)*number; 

        if(x0point1 > 0) count11+=(number-1)*m1;

        cout<<count11<<endl;

    }
    
    return 0;
}

