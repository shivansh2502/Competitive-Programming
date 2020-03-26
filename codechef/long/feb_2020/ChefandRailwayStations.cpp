#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

bool isPerfectSquare(ll x){   
  long double sr = sqrt(x); 
  return ((sr - floor(sr)) == 0); 
} 



int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    ll  t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        unordered_set<ll> xpos;
        unordered_set<ll> xneg;
        unordered_set<ll> ypos;
        unordered_set<ll> yneg;
        // set<pair<long double,long double>> sx;
        // set<pair<long double,long double>> sy;

        ll x0point=0;
        ll y0point=0;
        for(ll i=0;i<n;i++){
            ll k;
            cin>>k;
            if(k>0) xpos.insert(k);
            else if(k<0) xneg.insert( k);
            else x0point++;
        }
        for(ll i=0;i<m;i++){
            ll q;
            cin>>q;
            if(q>0) ypos.insert(q);
            else if(q<0) yneg.insert( q);
            else y0point++;
        }
        ll count=0;
        
        if(x0point > 0) count+=(n-1)*m;
        if(y0point > 0) count+=(m-1)*n; 

        for(auto a:xpos){
            ll sq= a*a;
            for(ll i=1;i<=sqrt(sq);i++){
                if(sq%i==0){
                    if(i==sq/i){
                        if(ypos.find(i)!= ypos.end() && yneg.find(-i)!= yneg.end() ){
                            count++;
                        }
                    }
                    else{
                        if(ypos.find(i)!= ypos.end() && yneg.find(-sq/i)!= yneg.end()){
                           count++;
                        }    
                        if(ypos.find(sq/i)!= ypos.end() && yneg.find(-i)!= yneg.end()){
                            count++;
                        }
                    }
                }
            }
        }

        for(auto a:xneg){
            ll sq= a*a;
            for(ll i=1;i<=sqrt(sq);i++){
                if(sq%i==0){
                    if(i==sq/i){
                        if(ypos.find(i)!= ypos.end() && yneg.find(-i)!= yneg.end() ){
                                count++;
                        }
                    }
                    else{
                        if(ypos.find(i)!= ypos.end() && yneg.find(-sq/i)!= yneg.end()){
                                count++;
                        }    
                        if(ypos.find(sq/i)!= ypos.end() && yneg.find(-i)!= yneg.end()){
                                count++;
                        }
                    }
                }
            }
        }

        for(auto a:yneg){
            ll sq= a*a;
            for(ll i=1;i<=sqrt(sq);i++){
                if(sq%i==0){
                    if(i==sq/i){
                        if(xpos.find(i)!= xpos.end() && xneg.find(-i)!= xneg.end() ){
                            count++;
                        }
                    }
                    else{
                        if(xpos.find(i)!= xpos.end() && xneg.find(-sq/i)!= xneg.end()){
                                count++;
                        }    
                        if(xpos.find(sq/i)!= xpos.end() && xneg.find(-i)!= xneg.end()){
                                count++;
                        }
                    }
                }
            }
        }

        for(auto a:ypos){
            ll sq= a*a;
            for(ll i=1;i<=sqrt(sq);i++){
                if(sq%i==0){
                    if(i==sq/i){
                        if(xpos.find(i)!= xpos.end() && xneg.find(-i)!= xneg.end() ){
                                count++;
                        }
                    }
                    else{
                        if(xpos.find(i)!= xpos.end() && xneg.find(-sq/i)!= xneg.end()){
                                count++;
                        }    
                        if(xpos.find(sq/i)!= xpos.end() && xneg.find(-i)!= xneg.end()){
                                count++;
                        }
                    }
                }
            }
        }

        cout<<count<<"\n";
    }
    
    return 0;
}

