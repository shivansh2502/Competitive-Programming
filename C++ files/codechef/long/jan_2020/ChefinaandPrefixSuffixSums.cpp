#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;


ll  power(ll  a, ll  b) 
{ 
    ll  m = 1000000007;
    ll  result = 1; 
  
    while (b > 0) { 
        if (b & 1) 
            result = ((result % m) * (a % m)) % m; 
  
        b = b >> 1;
        a = ((a % m) * (a % m)) % m;
    } 

    return result%m; 

}

ll  gcdExtended(ll  a, ll  b, ll  *x, ll  *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll  x1, y1;
    ll  gcd = gcdExtended(b%a, a, &x1, &y1); 

    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 


ll  modInverse(ll  b, ll  m) 
{ 

    ll  x, y;  
    ll  g = gcdExtended(b, m, &x, &y); 
  

    if (g != 1) 
        return -1; 
  

    return (x%m + m) % m; 
} 

ll modD(ll  a, ll  b, ll  m) 
{ 

    a = a % m; 

    ll inv = modInverse(b, m); 

    if (inv == -1) 
       return ((a%m)/(b%m))%m;

    else
       return ((inv%m) * (a%m)) % m; 
} 


int main(){


    ios::sync_with_stdio(false);
    cin.tie(0);


    ll  m = 1000000007;

    ll factorial[100005]; 

    factorial[0]=factorial[1]=1;

    for(ll i=2;i<100005;i++){

        factorial[i]=((i%m)*(factorial[i-1]%m))%m;

    }

    ll  test;
    cin>>test;
    
    while(test--){

        ll  n1;
        cin>>n1;

        ll  arr[2*n1];

        unordered_map<ll ,ll > map;

        ll  summ=0;
        for(ll  i=0;i<2*n1;i++){
            cin>>arr[i];

            map[arr[i]]++;

            summ+=arr[i];
        }


        ll  totall=summ/(n1+1);

        if(map[totall]<2){

            cout<<0<<"\n";

            continue;
        }

        map[totall]-=2;

        bool f=true;

        ll  answer=((factorial[n1-1]%m) * (power(2,n1-1)%m))%m;

        for(auto it:map){

            if(map.count(totall-it.first)==true){

                if(it.second==map[totall-it.first] && it.second>0 && map[totall-it.first]>0){

                    if(it.first==totall-it.first){

                        answer=modD(answer, power(2,it.second/2), m); 
                        answer=modD(answer, factorial[it.second/2], m);

                    }

                    else{

                        answer=modD(answer, factorial[it.second], m);

                    }

                    map[totall-it.first]=0;
                    map[it.first]=0;

                }
            }
        }

        for(auto it:map){

            if(it.second!=0){
                f=false;
                break;

            }

        }

        if(f==false){

            cout<<0<<"\n";
            continue;

        } 

        cout<<answer%m<<"\n";
    }
    return 0;
}
