#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
	ll t;
	cin >> t;

	while(t--){
	    ll  a,b,c;
        cin>>a>>b>>c;
        
        ll  mindiff=INT_MAX;

        for(ll  i=a-1;i<=a+1;i++){
            for(ll  j=b-1;j<=b+1;j++){
                for(ll  k=c-1;k<=c+1;k++){
                    ll  diff=abs(i-j)+abs(j-k)+ abs(k-i);
                    mindiff=min(diff, mindiff);
                }
            }
        }
        cout<<mindiff<<endl;

	}
}