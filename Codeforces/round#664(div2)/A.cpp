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
        int r, g, b, w;
        cin>>r>>g>>b>>w;
        if(r==0 && g==0 && b==0 && w==0){
            cout<<"Yes"<<endl;
            continue;
        }
       
        bool flag=false;
        while(r>0 || g>0 || b>0 || w>0){
            int count=0;
            if(r==0) count++;
            if(g==0) count++;
            if(b==0) count++;
            int odd=0, even=0;
            if(r%2==0) even++;
            else odd++;
            if(g%2==0) even++;
            else odd++;
            if(b%2==0) even++;
            else odd++;
            if(w%2==0) even++;
            else odd++;
            if(even==4){
                flag=true;
                break;
            }
            if(even==3 && odd==1){
                flag=true;
                break;
            }
            if(odd==3 && even==1 && count==0){
                flag=true;
                break;
            }
            if(odd==4 && count==0){
                flag=true;
                break;
            }
            if(odd==2 && even==2 && count==0){
                flag=false;
                break;
            }
            if(r>0) r--;
            else break;
            if(g>0) g--;
            else break;
            if(b>0) b--;
            else break;
            w+=3;
        } 
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    
    return 0;
}


