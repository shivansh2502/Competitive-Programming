#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;


ll myfunction(string aabb, string bbcc)
{
    ll final_length = aabb.length();

        ll final_ans=0;
    
        for(ll i=0 ; i < final_length ; i++)
        {
            ll mycount=0;
            if(aabb[i]=='1' && bbcc[i]=='1')
            {
                ll j=i;
                mycount=1;
                for(j=i+1 ; j < final_length ; j++)
                {
                    if((aabb[j]=='1' && bbcc[j]=='0') || (aabb[j]=='0' && bbcc[j]=='1'))
                    {
                        mycount++;
                    }
                    else
                    {
                        break;
                    }
                }
                final_ans=max(mycount,final_ans);
            }
        }

    return final_ans;
}


int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        string aabb;
        string bbcc;

        cin>>aabb>>bbcc;

        auto x=bitset<10005>(bbcc);

        reverse(aabb.begin(), aabb.end());
        
        reverse(bbcc.begin(), bbcc.end());

        if(aabb.length() < bbcc.length())
        {
            for(ll ittr=aabb.length() ; ittr < bbcc.length() ; ittr++)
            {
                aabb+='0';
            }
        }
        else{
             for(ll ittr=bbcc.length() ; ittr < aabb.length() ; ittr++){
                bbcc+='0';
            }
        }

        ll final_ans= myfunction(aabb, bbcc);    
        
        if(x.count()>0)
        {
            cout<<final_ans+1<<endl;
        }
        else
        {
            cout<<final_ans<<endl;
        }
    }
    return 0;
}