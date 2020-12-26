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
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
}


int power(int x, int y, int p){ 
    int res = 1;  
    x = x % p; 

    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
  
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 
  
int modInverse(int n, int p){ 
    return power(n, p - 2, p); 
}

int nCrModPFermat(int n, int r, int p){ 
    
    if (r == 0) 
        return 1; 
  
    int fac[n + 1]; 
    fac[0] = 1; 
    for (int i = 1; i <= n; i++) 
        fac[i] = (fac[i - 1] * i) % p; 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 

int32_t main(){
    sm25official();

    w(t){
        int n;
        cin>>n;

        int c[n];
        f(i, n) cin>>c[i];

        sort(c, c+n, greater<int>());

        int high=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            if(c[i]> high){
                high=c[i];
                count=1;
            }
            else if(c[i]==high) count++;
            else break;
        }

        int ans=0;
        if(count%2!=0) ans= mpow(2, n);
        else ans= ((mpow(2, n)%mod) - ((nCrModPFermat(count, count/2, mod)%mod)*(mpow(2, n-count)%mod))%mod  +  mod) % mod;
        cout<<ans<<endl;

    }
    
    return 0;
}