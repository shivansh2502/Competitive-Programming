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

    int n, q;
    cin>>n>>q;

    vector<int> a(n), b(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>b[i];

    vector<int> cici(n), didi(n);
    int max_c_current=INT_MIN, min_c_current= INT_MAX, max_d_current=INT_MIN, min_d_current= INT_MAX;

    f(i, n){
        cici[i]= a[i]+b[i];
        didi[i]= a[i]-b[i];
        max_c_current= max(max_c_current, cici[i]);
        min_c_current= min(min_c_current, cici[i]);
        max_d_current= max(max_d_current, didi[i]);
        min_d_current= min(min_d_current, didi[i]);
    }
    
    while(q--){
        char s;
        cin>>s;
        if(s=='?'){
            cout<<max(max_c_current- min_c_current , max_d_current- min_d_current)<<endl;
        }
        else if(s=='a'){
            int x, y;
            cin>>x>>y;
            x--;
            a[x]=y;
            cici[x]= a[x] + b[x];
            didi[x]= a[x] - b[x];
            max_c_current=INT_MIN, min_c_current= INT_MAX, max_d_current=INT_MIN, min_d_current= INT_MAX;
            f(i, n){
                max_c_current= max(max_c_current, cici[i]);
                min_c_current= min(min_c_current, cici[i]);
                max_d_current= max(max_d_current, didi[i]);
                min_d_current= min(min_d_current, didi[i]);
            }
        }
        else{
            int x, y;
            cin>>x>>y;
            x--;
            b[x]=y;
            cici[x]= a[x]+ b[x];
            didi[x]= a[x]- b[x];
            max_c_current=INT_MIN, min_c_current= INT_MAX, max_d_current=INT_MIN, min_d_current= INT_MAX;
            f(i, n){
                max_c_current= max(max_c_current, cici[i]);
                min_c_current= min(min_c_current, cici[i]);
                max_d_current= max(max_d_current, didi[i]);
                min_d_current= min(min_d_current, didi[i]);
            }
        }
    }
    
    return 0;
}





