#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll1;


ll1  gcdExtended(ll1  a, ll1  b, ll1  *x, ll1  *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll1  x1, y1;
    ll1  gcd = gcdExtended(b%a, a, &x1, &y1); 

    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 


ll1  modInverse(ll1  b, ll1  m)
{ 

    ll1  x, y;  
    ll1  g = gcdExtended(b, m, &x, &y); 
  

    if (g != 1) 
        return -1; 
  

    return (x%m + m) % m; 
} 

ll1 modDivi(ll1  a, ll1  b, ll1  m)
{ 

    a = a % m; 

    ll1 inv = modInverse(b, m); 

    if (inv == -1) 
       return ((a%m)/(b%m))%m;

    else
       return ((inv%m) * (a%m)) % m; 
} 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll1 test;
    cin>>test;

    ll1 mod= 1000000007;
    while(test--){
        ll1 number;
        cin>>number;

        string str;
        cin>>str;

        ll1 tc=0;

        ll1 ques= (( number%mod *( (number+1)%mod )) %mod)/2; 

    
        for(ll1 ittr=0;ittr<number;ittr++){

            ll1 close=0, open=0;
            int ch=0;

            for(ll1 jttr=ittr;jttr<number;jttr++){

                if(str[jttr]==')'){
                    close++;

                    if(close>open){
                        ch= ch+1;
                        close--;
                        open++;
                    }

                }
                else if(str[jttr]=='('){

                    open++;

                }

                tc+=ch;
            }
        }
       
        cout<<modDivi(tc, ques, mod)<<endl;
    }
    
    return 0;
}
