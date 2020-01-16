#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
       ll n;
        cin>>n;
        ll cost[n];
        ll petrol[n];
        for(ll i=0;i<n;i++){
            cin>>cost[i];
        }
        for(ll i=0;i<n;i++){
            cin>>petrol[i];
        }
        ll min_cost=cost[0];
        ll total=min_cost*petrol[0];
        for(ll i=1;i<n;i++){
            if(min_cost>cost[i]){
                min_cost=cost[i];
                total=total+min_cost*petrol[i];
                continue;
            }
            else{
                total=total+min_cost*petrol[i];
                continue;
            }
        }
        cout<<total<<endl;
    }
}
