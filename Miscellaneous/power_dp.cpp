#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll powe[100005]={0};

ll power(ll x,ll y) 
{ 
    if(powe[y]!=0){
        return powe[y];
    }
    else if( y == 0){
        powe[y]=1;
        return powe[y];
    }  
    powe[y/2] = power(x, y/2); 
    if (y%2 == 0) 
        powe[y]=powe[y/2]*powe[y/2];

    else
        powe[y]=x*powe[y/2]*powe[y/2];
    return powe[y];
} 

int main(){
    cout<<power(2,2)<<endl;
    return 0;
}