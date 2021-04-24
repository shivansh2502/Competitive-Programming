#include<bits/stdc++.h>
using namespace std;
#define bitCount(num)  __builtin_popcount(num)
#define pb push_back
#define ll long long
#define bye return 0;
#define f(i,a,b) for( long long i=a;i<b;i++)
#define r(i,a,b) for(long long i=a;i>=b;i--);
#define testCases long long t;cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define conti continue;
#define vll vector<long long>
#define ofSize(a,n) a=vector<long long>(n,0);
#define show(a) for(long long i=0;i<a.size();i++) cout<<a[i]<<" ";
#define showR(a) for(long long i= a.size()-1 ;i>=0 ;i--) cout<<a[i]<<" ";
 
 
ll n,m,o,p,x,y,z;
vll a,b,c,d;
 
int main()
{
    fast
    testCases{
    	cin>>n;
    	ofSize(a,n);
    	f(i,0,n) cin>>a[i];
    	ll evenC=0;
    	ll oddC=0;
    	f(i,0,n) if(a[i]%2) oddC++;
    	         else evenC++;
 
        ll odd =0;
        ll even=0;
        f(i,0,n)if(a[i]%2) odd+=a[i];
        else even+=a[i];

        vector<ll> e,o;
        e.pb(INT_MIN);
        o.pb(INT_MIN);
        f(i,0,n) if(a[i]%2) o.pb(a[i]);
        else e.pb(a[i]);

        sort(all(e));
        sort(all(o));
        // for(auto ele: o) cout<<ele<<" ";
        // 	cout<<endl;
        if(e.size()==0)
        {
        cout<<"Bob\n";
        continue;
        }
        if(o.size()==0)
        {
        cout<<"Alice\n";
        continue;
        }
        bool turn =1;

        int i = e.size()-1;
        int j = o.size()-1;
        bool ans= false;
        ll al=0;
        ll bob=0;
        while(i>=1 || j>=1){
            if(turn == 1 && e[i]>o[j])
            {
            al+=e[i];
            i--;
            }
            else if(turn == 0 && o[j]>e[i])
            {
            bob+=o[j];
            j--;
            }
            else if(o[j]>e[i]) j--;
            else if(e[i]>o[j]) i--;
            turn ^=1;
            // cout<<al<<" "<<bob<<endl;
        }
 
       
     if(al>bob) cout<<"Alice\n";
     else if(al<bob) cout<<"Bob\n";
     else cout<<"Tie\n";
    }
    bye
}
