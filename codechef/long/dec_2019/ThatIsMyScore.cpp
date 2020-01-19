#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;


ll totalsum( unordered_map<ll,ll> map)
{

    ll Final_Sum=0;
    
    for(auto i:map)
    {
        if(i.first<9)
        {
            Final_Sum+=i.second;
        }
    }

    return Final_Sum;

}


int main()
{

    ll test;
    cin>>test;


    while(test--)
    {

        ll next;
        cin>>next;

        unordered_map<ll,ll> hashmap;

        for(ll i=0;i<next;i++)
        {
            ll pi,si;
            cin>>pi>>si;

            if(hashmap[pi]<si && pi<9)
            {
                hashmap[pi]=si;
            }

        }


        ll Final_Sum=totalsum(hashmap);


        
        cout<<Final_Sum<<endl;

    }

    return 0;
}