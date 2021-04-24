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
        string s;
        cin >> s;

        vector<int> cc(26,0);
        
        for(char c : s)
            cc[c-'a']++;
         
        int occured = 0;
        for(int i = 0 ; i < 26 ; i++)
            occured += (cc[i] & 1);
        
        // more than one element occured odd no. of times
        if(occured > 1){
            cout << -1 << endl;
            continue;
        }
        
        // core begins
        int end = s.length()-1, ans = 0;
        for(int i = 0 ; i < s.length()/2 ; i++){
            if(s[i]==s[end-i])
                continue;
            
            // proceed if ends are not same
            int j, k;
            for(j = i+1 ; j <= end-i && s[j]!=s[end-i] ; j++);
            for(k = end-i-1; k >= i && s[k]!=s[i] ; k--);
            
            // choose minimum distance
            ans += min(j-i, end-i-k);
            if( j-i < end-i-k){                    
                for(int p = j; p > i ; p--)
                    swap(s[p], s[p-1]);
            }else{
                for(int p = k ; p < end-i ; p++)
                    swap(s[p], s[p+1]);
            }            
        }
        
        cout << ans << endl;
    }
    return 0;
}

// 2
// aabb
// aa