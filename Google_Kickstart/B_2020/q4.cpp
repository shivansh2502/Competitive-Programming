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


bool isSafe(int x, int y, int l, int u, int r, int d, int w, int h){
    if(x<1 || y<1) return false;
    if(x>=l && y<=r && y>=u && u<=d) return false;
    else return true;
}
int dp[1000][1000];
int func(int w1, int h1,int l, int u, int r, int d, int w, int h){

    if(w1==1 || h1==1){
        return 1;
    }
    if(dp[w1][h1]!=-1) return dp[w][h];

    int ans1=0;
    int ans2=0;
    if(isSafe(w1-1, h1, l, u, r, d, w, h)) ans1=func(w1, h1-1, l, u, r, d, w, h); 

    if(isSafe(w1, h1-1, l, u, r, d, w, h)) ans2=func(w1, h1-1, l, u, r, d, w, h);

    dp[w][h]= ans1+ans2;
    return ans1+ans2;
    
   
    // // cout<<x<<" "<<y<<"->"<<ans1<<" "<<ans2<<endl;
    // if(ans1==0 && ans2==0){
    //     return 0;
    // }
    // else if(ans1==0 &&ans2!=0){
    //     double o= ans2/2;
    //     return o;
    // }
    // else if(ans1!=0 &&ans2==0){
    //     double o= ans1/2;
    //     return o;
    // }
    // else{
    //     double o = (ans1*(w-x))+(ans2*(h-y))/((w-x)*(h-y));
    //     return o;
    // }
}


int32_t main(){
    sm25official();
    int k=1;
    w(t){
        memset(dp, -1, sizeof(dp));
        cout<<"Case #"<<k<<": ";
        int w, h;
        cin>>w>>h;
        int l, u, r, d;
        cin>>l>>u>>r>>d;
        int x=1,y=1;
        double ans= func(x, y, w, h, l, u, r, d);
        cout<<ans<<endl;
        for(int i=0;i<w;i++){
            for(int j=0;j<=h;j++){
                cout<<dp[w][h]<<" ";
            }
            cout<<endl;
        }
        k++;
    }
    
    return 0;
}


