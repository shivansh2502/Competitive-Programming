#include<bits/stdc++.h>

#include<iostream>

#include<algorithm>

#include<math.h>

using namespace std;

typedef long long ll;




ll  power(ll  a, ll  b){ 


    ll  t; 
    if( b == 0) 
        return 1; 

    t = power(a, b/2); 

    if (b%2 == 0) 
        return t*t; 
    else
        return a*t*t; 

} 




int main(){

    ll test;
    cin>>test;

    while(test--){
        ll num;
        cin>>num;

        ll a1;
        cin>>a1;

        ll s1=2*power(10,num) + a1;
        cout<<s1<<endl;

        ll b1;
        cin>>b1;

        ll c1=power(10,num)-b1;
        cout<<c1<<endl;

        ll d1;
        cin>>d1;

        ll e1=power(10,num)-d1;
        cout<<e1<<endl;

        ll answer;
        cin>>answer;
        
    }
    return 0;
}