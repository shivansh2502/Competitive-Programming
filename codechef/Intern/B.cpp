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


class graph{
    unordered_map<int, list<pair<int,int>>> adjlist;
public:
    void addedge(int u, int v, int dist){
        adjlist[u].push_back(make_pair(v,dist));
        adjlist[v].push_back(make_pair(u,dist));
    }

    int bfs(int u, int v){
        
        queue<pair<int, int>> q;
        map<int,bool> visited;

        q.push(mp(u, 0));
        visited[u]=true;
       
        while(!q.empty()){
            auto t= q.front();
            int top= t.ff;
            int dist= t.ss;
            // cout<<top<<" "<<dist<<endl;
            if(top==v) return dist;
            q.pop();
            for(auto i:adjlist[top]){
                if(!visited[i.ff]){
                    q.push(mp(i.ff, dist+i.ss));
                    visited[i.ff]=true;
                }
            }
        }
        return -1;
    }

};


int32_t main(){
    sm25official();

    w(t){
        int n, q, r;
        cin>>n>>q>>r;

        graph g;

        f(i, n-1){
            int u, v, w;
            cin>>u>>v>>w;
            g.addedge(u, v, w);
        }

        f(i, q){
            int u, v;
            cin>>u>>v;
            cout<<g.bfs(u, v)<<endl;
        }
    }
    
    return 0;
}