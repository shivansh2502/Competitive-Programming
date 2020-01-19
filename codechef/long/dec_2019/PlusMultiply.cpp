#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;


ll functionforans(ll cofall2, ll cofall0)
{

    ll final_ans=( cofall2 * ( cofall2 - 1 ) ) / 2 + ( cofall0 * ( cofall0 - 1 ) ) /2;

    return final_ans;

}


int main()
{

    ll test;

    cin>>test;

    while(test--)
    {

        ll next;
        cin>>next;

        ll array[next];

        ll cofall2=0;

        ll cofall0=0;


        for(ll ittr=0; ittr < next; ittr++)
        {
            cin>>array[ittr];

            if(array[ittr]==2)
            {
                cofall2++;
            }

            else if(array[ittr]==0)
            {
                cofall0++;
            }

        }

        ll final_ans=  functionforans(cofall2, cofall0);

        cout<<final_ans<<endl;
    }

    return 0;

}