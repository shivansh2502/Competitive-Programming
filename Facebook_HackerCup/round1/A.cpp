#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define f(i,n)			for(int i=0;i<n;i++)
#define fs(i,s,n)		for(int i=s;i<n;i++)
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define MOD             998244353;
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define PI              3.1415926535897932384626

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;



int inv(int a) {
    int r = 1, t = a, k = MOD - 2;
    while (k) {
        if (k & 1) r = (long long) r * t % MOD;
        t = (long long) t * t % MOD;
        k >>= 1;
    }
    return r;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}
 
 
void sm25official()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main(){
    sm25official();

    int tx=1;
    w(t){
        int n, k, w;
        cin>>n>>k>>w;
        int l[n];
        f(i, k) cin>> l[i];
        int al, bl, cl, dl;
        cin>>al>>bl>>cl>>dl;
        int h[n];
        f(i, k) cin>> h[i];
        int ah, bh, ch, dh;
        cin>>ah>>bh>>ch>>dh;

        for(int i=k;i<n;i++){
            l[i]= ((  ((al%mod)* (l[i-2]%mod))%mod + (bl%mod * l[i-1]%mod)%mod +cl%mod ) % dl)%mod + 1;
            l[i]= l[i]%mod;
            h[i]= ((  ((ah%mod)* (h[i-2]%mod))%mod + (bh%mod * h[i-1]%mod)%mod +ch%mod ) % dh)%mod + 1;
            h[i]= h[i]%mod;
        }        
        
        int p[n];
        p[0]= 2*(w + h[0]);
        int lastl=0;
        int maxh=h[0];
        fs(i, 1, n){
            l[i]= l[i]%mod;
            h[i]= h[i]%mod;
            if(l[i-1]+w >= l[i]){
                maxh= max(h[i], maxh);
                int curper= ((2*maxh)%mod + (2*(l[i]+w -l[lastl]))%mod)%mod;
                if(lastl>0){
                    curper= (curper%mod+ p[lastl-1]%mod)%mod;
                }
                p[i]= curper%mod;
            }
            else{
                p[i]= (p[i-1]%mod + 2*(w+h[i])%mod)%mod;
                maxh=h[i];
                lastl= i;
            }
        }


        int ans=1;
        f(i, n){
            // cout<<p[i]<<" ";
            ans= ((ans%mod) * (p[i]%mod))%mod;
            ans= ans%mod;
        }
        // cout<<endl;
        cout<<" Case #"<<tx<<": ";
        cout<<ans<<endl;
        tx++;
    }
    
    return 0;
}


