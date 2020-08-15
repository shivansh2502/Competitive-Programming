#include<bits/stdc++.h>
using namespace std;
#define  forloop for(int i=0;i<n;i++)
#define pb push_back 
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define MOD 998244353;
#define unmap unordered_map
#define pi 3.1415926536
#define testcases ll t;cin>>t;while(t--)
#define  mp make_pair
#define  vcp vector<pair<ll,ll>>
#define preci(x,y)  fixed<<setprecision(y)<<x
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define fast ios::sync_with_stdio(false); 	cin.tie(0); cout.tie(0);
#define preinc priority_queue <ll, vector<ll>, greater<ll>>
#define predec priority_queue<ll> 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	fast
	testcases{
	ull n,x;
	cin>>n>>x;
	ll a[n];
	forloop
	{
		cin>>a[i];
	}
	ull e=x;
    sort(a,a+n,greater<ll>());

	ull c=0;

	for(int i=0;i<n;i++)
	{
		if(x>=a[i])
		{
			c++;
			x=2*a[i];
		}
		else
		{
			ll f=1;
			ll val=a[i];
			ll fd=val;
			while(true)
			{
				if(x>=val)
				break;
		
			val-=x;
				x=2*x;
			val=val*2;
			if(val>fd)
			val=fd;
			f++;
			}
			x=fd*2;
			c+=f;
		}
	}

    x=e;
    sort(a,a+n);
    ull d=0;

	for(int i=0;i<n;i++)
	{
		if(x>=a[i])
		{
			d++;
			x=2*a[i];
		}
		else
		{
			ll f=1;
			ll val=a[i];
			ll fd=val;
			while(true)
			{
				if(x>=val)
				break;
		
			val-=x;
				x=2*x;
			val=val*2;
			if(val>fd)
			val=fd;
			f++;
			}
			x=fd*2;
			d+=f;
		}
	}

	cout<<min(d,c)<<"\n";
	}
	// your code goes here
	return 0;
}