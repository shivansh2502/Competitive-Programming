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


vector<unordered_set<int>> dp(200005);
template <typename T>
class graph{
public:
    map<T, list<T>> adjlist;

    void addedge(T u, T v, bool bidir=true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    } 

    bool dfsHelper(int s, int e , map<int, bool> &visited, int si){
        visited[s]=true;
        if(s==e){
            dp[s].insert(s);
            return true;
        }

        if(!dp[s].empty()){
            for(auto i: dp[s]){
                dp[si].insert(i);
            }
            return  true;
        }

        for(auto i: adjlist[s]){
            if(!visited[i]){
                bool flag= dfsHelper(i, e, visited, si);
                if(flag){
                    dp[si].insert(i);
                    for(auto i:dp[i]){
                        dp[s].insert(i);
                    }
                    dp[s].insert(s);
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(int s, int e){
        map<int, bool> visited;
        if(s==e){
            dp[s].insert(e);
            return;
        }
        if(!dp[s].empty()) {
            dp[s].insert(s);
            return;
        }
        bool ans=dfsHelper(s, e, visited, s);
        dp[s].insert(s);
        return;
    }
};

int32_t main(){
    sm25official();
    int n, q;
    cin>>n>>q;
    graph<int> g;
    f(i, n-1){
        int u, v;
        cin>>u>>v;
        g.addedge(u, v);
    }
    fs(i,1, n){
        dp[i].clear();
    }
    
    f(i, q){
        int m;
        cin>>m;
        int a[m];
        map<int, int> um;
        unordered_set<int> se;
        f(i, m){
            cin>>a[i];
            se.insert(a[i]);
            g.dfs(a[i], 1);
        }
        bool flag=false;
        for(auto i:se){
            // cout<<i<<"->";
            for(auto j:dp[i]){
                // cout<<j<<" ";
                if(se.count(j)){
                    um[j]++;
                    if(um[j]==m){
                        cout<<j<<endl;
                        flag= true;
                        break;
                    }
                }
            }
            // cout<<endl;
        }

        if(!flag){
            cout<<-1<<endl;
        }

    }
    
    return 0;
}


