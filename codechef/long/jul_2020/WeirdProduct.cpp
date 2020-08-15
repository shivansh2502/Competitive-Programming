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
#define mod             998244353
// #define MOD             998244353;
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define PI              3.1415926535897932384626

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;



// int inv(int a) {
//     int r = 1, t = a, k = MOD - 2;
//     while (k) {
//         if (k & 1) r = (long long) r * t % MOD;
//         t = (long long) t * t % MOD;
//         k >>= 1;
//     }
//     return r;
// }

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
    int MOD = 998244353;
    w(t){
        int n, x;
        cin>>n>>x;
        int a[n];
        bool flag=true;
        f(i, n){
            cin>>a[i];
            if(a[i]==0){
                flag=false;
            }
        }
        if(!flag){
            cout<<0<<endl;
            continue;
        }
        int pre[n];
        int s=0;
        for(int i=0;i<n;i++){
            s+=((a[i] % MOD) *(mpow(x, i) % MOD))%MOD;
            pre[i]=s;
        }
        int final=1;
        int sum=0;

        for(int i=0;i<n;i++){
            for()
        }
        
        for(int i=0; i<n; i++){
            sum+=((a[i] % MOD) *(mpow(x, i) % MOD))%MOD;
            int sq= mpow(sum, 2)%MOD;
            final= ((final % MOD) * (mpow(sq, n-i) % MOD))%MOD;
            
        }
        cout<<final<<endl;

        
    }
    
    return 0;
}


// a0^2* (a0+a1*x)^2* (a0+a1*x+a2*x^2)^2* a1^2* (a1+a2*x)^2* a2*2   


/*


a0* (a0+a1*x)* (a0+a1*x+a2*x^2)* a1* (a1+a2*x)* a2
= a0a1a2 *(a0+a1x) *(a1+a2x)*(a0+a1x+a2x^2)
= (a0^2a1a2+ a0a1^2a2x) *(a1+ a2x) *(a0+ a1x+ a2x^2)

= (a0^2a1^2a2+ a0a1^3a2x+ a0^2a1a2^2x+ a0a1^2a2^2x^2) *( a0 + a1x+ a2x^2)

= (a0^3a1^2a2+ a0^2a1^3a2x+ a0^3a1a2^2x+ a0^2a1^2a2^2x^2)+
(a0^2a1^3a2x+ a0a1^4a2x^2+ a0^2a1^2a2^2x^2+ a0a1^3a2^2x^3)+
(a0^2a1^2a2^2x^2+ a0a1^3a2^2x^3+ a0^2a1a2^3x^3+ a0a1^2a2^3x^4)

= a0^3a1^2a2+ ( a0^3a1a2^2+ 2a0^2a1^3a2)x +
(a0a1^4a2+ 3*a0^2a1^2a2^2)x^2 + 
(2a0a1^3a2^2+ a0^2a1a2^3)x^3+ a0a1^2a2^3x^4

= a0^3a1^2a2+  a0^2a1a2( a0a2+ 2a1^2)x+
 a0a1^2a2(a1^2+ 3*a0a2)x^2 + 
 a0a1a2^2( a0a2 + 2a1^2)x^3 + a0a1^2a2^3x^4

------------------------------------------------------------------------

(a0+a1*x)* (a1+a2*x)* (a0+a1*x+a2*x^2)
= (a0a1+ a0a2x+ a1^2x+ a1a2x^2) * (a0 + a1x + a2x^2)

= a0^2a1 + a0a1^2x + a0a1a2x^2 +  a0^2a2x + a0a1a2x^2 + a0a2^2x^3 + a0a1^2x + a1^3x^2 +
a1^2a2x^3 + a0a1a2x^2 + a1^2a2x^3 + a1a2^2x^4

= a0^2a1 + (a0^2a2 + 2a0a1^2)x + (a1^3+ 3a0a1a2)x^2 + (a0a2^2+ 2a1^2a2)x^3 + a1a2^2x^4




*/

