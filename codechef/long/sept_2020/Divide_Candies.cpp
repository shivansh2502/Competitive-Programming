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

    int k;
    cin>>k;

    w(t){
        int n;
        cin>>n;

        int sum=0;
        switch (k){
        case 1: sum= n*(n+1)/2;
            break;
        case 2: sum= n*(n+1)*(2*n + 1)/6;
            break;
        case 3: sum= (n*(n+1)/2)* (n*(n+1)/2);
            break;
        case 4: sum=  n*(1+n)*(1+2*n)*( -1 + 3*n + 3*n*n )/30;
            break;
        default: 
            break;
        }
        // cout<<sum<<endl;
        
        int csum=0;
        bool a[n+1]={0};
        for(int i=n;i>=1;i--){
            int dif= ((sum-csum) - csum)/2;
            if(dif>=pow(i, k)){
                csum+= pow(i, k);
                a[i]=1;
            }
        }
        cout<<endl;

        cout<< sum - 2* csum <<endl;

        fs(i,1,n+1){
            cout<<a[i];
        }
        cout<<endl;

    }
   
    return 0;
}

// 1 4 9 16 25
// 55

// 1 4 9 16 25 36
// 91

// 1 4 9 16 25 36 49
// 140

// 1 4 9 16 25 36 49 64 
// 204

// 1 4 9 16 25 36 49 64 81
// 285
 
// 1 4 9 16 25 --- 181, 149    36 49 64 81 100
// 385

// 1 4 9 16 25 36 49 64 81 100 121 144 169 196 225
// 1240