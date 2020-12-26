#include<bits/stdc++.h>
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

#define MAXN 100000 
#define level 18 

vector <int> tree[MAXN]; 
int depth[MAXN]; 
int parent[MAXN][level]; 
 

void dfs(int cur, int prev) { 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<tree[cur].size(); i++) 
    { 
        if (tree[cur][i] != prev) 
            dfs(tree[cur][i], cur); 
    } 
} 

void precomputeSparseMatrix(int n) { 
    for (int i=1; i<level; i++) 
    { 
        for (int node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
        } 
    } 
} 
 

int lca(int u, int v) { 
    if (depth[v] < depth[u]) 
        swap(u, v); 
 
    int diff = depth[v] - depth[u]; 
 
    for (int i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = parent[v][i]; 
 
    if (u == v) 
        return u; 
 
    for (int i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
 
    return parent[u][0]; 
} 
 
void addEdge(int u,int v) 
{ 
    tree[u].push_back(v); 
    tree[v].push_back(u); 
} 
 

int32_t main(){
    sm25official();
    memset(parent,-1,sizeof(parent)); 

    int n, x;
    cin>>n>>x;

    f(i, n-1){
        int a, b;
        cin>>a>>b;
        addEdge(a, b);
    }

    depth[0] = 0; 
    dfs(1,0);
    precomputeSparseMatrix(n); 

    int q;
    cin>>q;

    while(q--){
        int a, b;
        cin>>a>>b;

        int c1= lca(a, b);
        int c2= lca(a, x);
        int c3= lca(b, x);

        if(c1==c2 && c2==c3) cout<<c3<<endl;
        else if(c1==c2) cout<<c3<<endl; 
        else if(c2==c3) cout<<c1<<endl; 
        else if(c1==c3) cout<<c2<<endl; 
    }

    return 0;
}

/*
5 3
3 2
3 1
2 4
2 5
2
4 5
1 5
*/
