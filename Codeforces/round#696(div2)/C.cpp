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

    w(t){
        int n;
        cin>>n;
        int a[2*n];
        f(i, 2*n) cin>>a[i];
        sort(a, a+2*n);

        unordered_map<int, int> m;
        f(i, 2*n) m[a[i]]++;

        vector<pii> v;
        bool flag1=false;
        f(i, 2*n-1){
            unordered_map<int, int> um=m;
            v.clear();
            v.push_back({a[2*n-1], a[i]});
            um[a[2*n-1]]--;
            um[a[i]]--;
            int val= a[2*n-1];
            for(int j=2*n-2;j>=0;j--){
                if(um.count(a[j]) && um.count(val-a[j]) && um[a[j]]>0 && um[val-a[j]]>0){
                    if(a[j]==val-a[j] && um[a[j]]<=1){
                        break;
                    } else{
                        um[a[j]]--;
                        um[val-a[j]]--;
                        v.push_back({a[j], val-a[j]});
                        val= max(a[j], val-a[j]);
                    }
                }
            }
            bool flag=true;
            for(auto i:um){
                if(i.ss>0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                flag1=true;
                break;
            }
        }
        if(flag1){
            cout<<"YES"<<endl;
            cout<<v[0].ff+v[0].ss<<endl;
            for(auto i:v) cout<<i.ff<<" "<<i.ss<<endl;
        } else{
            cout<<"NO"<<endl;
        }

    }
    
    
    return 0;
}
