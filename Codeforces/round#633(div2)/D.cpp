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

    bool bfs(T src, set<int> leaves){
        queue<T> q;
        map<T,bool> visited;
        map<T, T> distance;
        q.push(src);
        visited[src]=true;
        distance[src]=0;

        while(!q.empty()){
            T top=q.front();
            // cout<<top<<" ";
            q.pop();
            for(auto i:adjlist[top]){
                if(!visited[i]){
                    distance[i]=distance[top]+1;
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        for(auto i: leaves){
            if(distance[i]%2!=0){
                return false;
            }
        }
        return true;
    }
};




int32_t main(){
    sm25official();
    int n;
    cin>>n;
    graph <int> g;
    f(i, n-1){
        int x, y;
        cin>>x>>y;
        g.addedge(x, y, true);
    }
    set<int> leaves;
    set<int> adjleaves;
    int root;
    for(auto i: g.adjlist){
        int count=0;
        set<int> adj;
        for(auto j:i.second){
            count++;
            adj.insert(j);
        }
        if(count==1){
            root=i.first;
            leaves.insert(i.first);
            adjleaves.insert(*adj.begin());
        }
    }
    bool fmin=g.bfs(root, leaves);
    if(fmin) cout<<1<<" ";
    else cout<<3<<" ";

    int fmax= n-1 - leaves.size() + adjleaves.size();
    cout<<fmax<<endl;
    return 0;
}


