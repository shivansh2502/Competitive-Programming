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
    if(a.ff==b.ff){
        return a.ss<b.ss;
    }
    return a.ff>b.ff;
    
}

bool comp1(pii a, pii b){
    if(a.ff==b.ff){
        return a.ss>b.ss;
    }
    return a.ff>b.ff;
    
}

int32_t main(){
    shivansh2502();
    int n, q;
    cin>>n>>q;
    int h[n];
    int a[n];
    f(i, n)cin>>h[i];
    f(i, n) cin>>a[i];

    
    

    while(q--){
        int ty;
        cin>>ty;
        if(ty==1){
            int b, k;
            cin>>b>>k;
            b--;
            a[b]=k;
        }
        else if(ty==2){
            int b, c;
            cin>>b>>c;
            b--; c--;
            
            if(b>=c){
                int ans=0;
                ans+=a[b];
                bool flag=true;
                int m= h[b];
                vector<pii> v;
                for(int i=b-1;i>=c;i--){
                    if(h[i]>=m){
                        cout<<-1<<endl;
                        flag=false;
                        break;
                    }
                    else v.push_back(mp(h[i],i));
                }
                sort(v.begin(), v.end(), comp);
                
                if(flag){
                    int ind=b;
                    for(int i=0;i<v.size();i++){
                        if(v[i].ss<ind){
                            ind= v[i].second;
                            ans+=a[ind];
                            if(ind==c) break;
                        }
                    }
                    cout<<ans<<endl;
                }
            }
            else if(b<c){
                int ans=0;
                ans+=a[b];
                bool flag=true;
                int m= h[b];
                vector<pii> v;
                for(int i=b+1;i<=c;i++){
                    if(h[i]>=m){
                        cout<<-1<<endl;
                        flag=false;
                        break;
                    }
                    else v.push_back(mp(h[i],i));

                }
                sort(v.begin(), v.end(), comp1);
                
                if(flag){
                    int ind=b;
                    for(int i=0;i<v.size();i++){
                        if(v[i].ss>ind){
                            ind= v[i].second;
                            ans+=a[ind];
                            if(ind==c) break;
                        }
                    }
                    cout<<ans<<endl;
                }
            }
        
        }
    }
    
    return 0;
}


