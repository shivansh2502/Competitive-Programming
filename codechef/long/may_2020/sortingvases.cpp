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
        int a[n+1];
        fs(i,1, n+1) cin>>a[i];
        vector<pii> v;
        unordered_map<int, set<int>> adjlist;
        f(i, m) {
            int x, y;
            cin>>x>>y;
            v.push_back(mp(x, y));
            adjlist[x].insert(y);
            adjlist[y].insert(x);
        }
        vector<bool> visited(n, false);
        int ans=0;
        if(m==0){
            fs(i,1, n+1){
                int j=i;
                int cycle=0;
                // cout<<i<<" "<<a[i]<<endl;
                if(a[j]!=j && !visited[j]){
                    while(!visited[j]){
                        visited[j]=1;
                        j=a[j];
                        cycle++;
                    }

                    if(cycle>0){
                        ans+=(cycle-1);
                    }
                }   
            }
            cout<<ans<<endl;
            continue;
        }
        
        fs(i,1, n+1){
            int j=i;
            int cycle=0;
            vector<int> cy;
            set<int> s;
            // cout<<i<<" "<<a[i]<<endl;
            if(a[j]!=j && !visited[j]){
                while(!visited[j]){
                    visited[j]=1;
                    cy.pb(j);
                    s.insert(j);
                    j=a[j];
                    cycle++;
                }
                for(auto i: cy) cout<<i<<" ";
                cout<<endl;

                if(cycle>3){
                    int cost=INT_MAX;
                    for(int i=0;i<cy.size();i++){
                        
                        int curcost=0;
                        for(auto j:s){
                            if(j!=cy[i]){
                                if(!adjlist[cy[i]].count(j)){
                                    curcost++;
                                }
                                if(curcost>cost){
                                    break;
                                }
                            }
                        }
                        cost= min(curcost, cost);
                    }
                }
                if(cycle>0){
                    ans+=(cycle-1);
                }
            }   
        }
        cout<<ans<<endl;

    }
    
    return 0;
}


