#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;


ll functionforans(unordered_map< char, list<ll>> unormap)
{
        ll md=INT_MAX;

        for(auto ittr: unormap)
        {
            ll v=-1;
            
            for(auto jttr: ittr.second)
            {
                if(v==-1)
                {
                    v=jttr;
                }
                else
                {
                    md=min(jttr-v, md);
                    v=jttr;
                }

            }
        
        }

        return md;
}


int main()
{
    ll test;

    cin>>test;


    while(test--)
    {
        ll next;

        cin>>next;

        string str;

        cin>>str;

        unordered_map<char, list<ll>> unormap;

        for(ll ittr=0 ; ittr<next ; ittr++)
        {
            unormap[str[ittr]].push_back(ittr);
        }


        ll md=functionforans(unormap);


        if(md==INT_MAX)
        {
            cout<<0<<endl;
        }

        else
        {
            cout<<next-md<<endl;
        }

    }

    return 0;
}

