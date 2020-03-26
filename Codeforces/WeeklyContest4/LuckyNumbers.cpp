#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll ans=2;
    ll smallans=2;
    for(ll i=2;i<=n;i++){
        smallans=smallans*2;
        ans+= (smallans);
    }
    cout<<ans<<endl;
	
	return 0;
}
