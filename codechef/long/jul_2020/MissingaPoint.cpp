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
 
 
void shivansh2502()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool comp(pii a, pii b){
    return a.ss < b.ss;
}

int32_t main(){
    shivansh2502();
    w(t){
        int n;
        cin>>n;
        vector<pair<int, int>> v1;
        v1.reserve(4*n-1);

        for(int i=0;i<4*n-1;i++){
            int a, b;
            cin>>a>>b;
            v1.pb(mp(a, b));
        }

        map<int, int> um1;
        map<int, int> um2;
        int x, y;
        for(auto &i: v1){
            um1[i.ff]++;
            um2[i.ss]++;
        }
        for(auto &i:um1){
            if(i.ss%2!=0){
                x=i.ff;
                break;
            }
        }
        for(auto &i:um2){
            if(i.ss%2!=0){
                y=i.ff;
                break;
            }
        }
        cout<<x<<" "<<y<<"\n";

    }
    
    return 0;
}


