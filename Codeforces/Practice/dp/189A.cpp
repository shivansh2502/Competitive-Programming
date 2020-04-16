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

//pure dp solution
int dp[4004]={1};
int func(int n, int a, int b, int c){

    if(n==0) return 0;

    if (dp[n]!= -2) return dp[n];

    if(n<a && n<b && n<c){
        dp[n]=-1;
        return -1;
    }

    int count1=0, count2=0, count3=0;
    if(n>=a) count1= func(n-a, a, b, c) +1;
    if(n>=b) count2= func(n-b, a, b, c) +1;
    if(n>=c) count3= func(n-c, a, b, c) +1;


    if(count1==0 && count2==0 && count3==0){
        dp[n]= -1;
        return -1;
    }

    int maxcount= max(count1, max(count2, count3));
    dp[n]= maxcount;
    return maxcount;
}

// standard solution


int32_t main(){
    sm25official();
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++) dp[i]= -2;
    
    //solution-1
    int ans= func(n, a, b, c);
    cout<<ans<<endl;

    //solution-2
    int pieces=0;
    for (int i = 0; i*a <= n; ++i){
		for (int j = 0; i*a + j*b <= n; ++j){
			int k = (n - i*a - j*b)/c;
			if (i*a + j*b + k*c == n)
			pieces = max(i + j + k, pieces);
		}
	}
	cout << pieces <<endl;
    return 0;
}


