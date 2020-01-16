#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;

ll full_power(ll xx, ll yy, ll pq) 
{ 
    ll result = 1;      
  
    xx = xx % pq;


    while (yy > 0) 
    { 
        if (yy & 1)
        { 


            result = (result*xx) % pq; 
        }
  
        yy = yy>>1;


        xx = (xx*xx) % pq; 
    }


    return result; 
} 

ll ModInv(ll n, ll p) 
{ 


    return full_power(n, p-2, p); 
} 

ll NCR(ll nn, ll rr, ll pq, ll factorial[]) 
{  


    if (rr==0)
    { 
      return 1;
    } 
  
    return ( factorial[nn] * ModInv( factorial[rr] , pq) % pq *  ModInv( factorial[nn - rr] , pq) % pq ) % pq; 

} 

ll myfunction(ll minimumset, ll maximumset , ll next)
{

    ll final_ans=0;

        ll modulo=1000000007;

        ll factorial[next+1]; 

        factorial[0] = 1;



        for (ll it=1 ; it<=next; it++)
        {
            factorial[it] = factorial[it-1] * it % modulo;
        }



        for( ll it=minimumset ; it <= maximumset ; it+=2 )
        {
            final_ans = ((final_ans % modulo)+(NCR(next , it , modulo , factorial) % modulo)) % modulo;
        }

    return final_ans;

}


int main()
{
    ll test;
    cin>>test;

    while(test--)
    {

        ll next;

        string first;

        string second;

        ll setfirst=0;
        
        ll setsecond=0;

        cin>>next;

        cin>>first>>second;

        

        bitset<100000> xxyy(first);

        bitset<100000> yyzz(second);

        setfirst = xxyy.count();

        setsecond = yyzz.count();

        ll maximumset = min(setfirst, next-setsecond) + min(setsecond, next - setfirst);
        
        ll minimumset=0;

        
        if( setsecond >= setfirst )
        {
            minimumset=setsecond - setfirst;
        }


        else
        {
            minimumset=setfirst - setsecond;
        }
        


        ll final_ans= myfunction(minimumset, maximumset, next);




        cout<<final_ans<<endl;
    }
    return 0;
}