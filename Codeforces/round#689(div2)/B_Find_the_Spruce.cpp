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
        int n, m;
        cin>>n>>m;
        char a[n][m];
        f(i, n){
            f(j, m) cin>>a[i][j];
        }

        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='*'){
                    dp[i][j]=1;
                    count++;
                }
            }
        }

        f(i, n){
            f(j, m){
                if(i>0 && j>0 && dp[i][j]>=1){
                    if(dp[i-1][j]>0 && dp[i][j-1]>0){
                        bool flag=true;
                        int l=0;
                        for(int k=j+1;k<m;k++){
                            if(dp[i][k]>=1) l++;
                            else break;
                        }
                        int val2= 2*l+1;
                        dp[i][j]= min(dp[i-1][j]+2, min(dp[i][j-1]+2, val2));
                        if(dp[i][j]>1) count+=dp[i][j]/2;
                    }
                }
            }
        }

        // f(i, n){
        //     f(j, m){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        cout<<count<<endl;

    }
    
    return 0;
}
