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
    unordered_map<int, list<int>> adjlist;
    unordered_map<int, int> nst_spl;
public:\

    void addedge(int u, int v){
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    } 

    graph(int n){
        f(i, n){
            list<int> l;
            adjlist[i] = l;
        }
    }

   

   void bfstraversal(vector<int>& spl){

        queue<pii> q;

        map<int, bool> visited;

        for(auto i : spl){
            q.push(mp(i,0));
            nst_spl[i] = 0;
        }

        while(!q.empty()){
            pii no = q.front();

            nst_spl[no.ff] = no.ss;

            q.pop();
           
            for(int i : adjlist[no.ff]){

                if(!visited[i] && !nst_spl.count(i)){
                    q.push(mp(i,no.second + 1));
                }
                visited[i] = true;
            }
        }
    }


    void Ans(int src){
        if(!nst_spl.count(src)) cout<<-1<<"\n";
        else cout<<nst_spl[src]<<"\n";
    }
};

int32_t main(){
    sm25official();

    w(t){
        int n, m, k;
        cin>>n>>m>>k;

        graph gh(n);
        f(i, m){
            int u, v;
            cin>>u>>v;
            gh.addedge(u, v);
        }

        vector<int> spl(k,0);
        f(i, k) cin>>spl[i];

        gh.bfstraversal(spl);

        w(q){
            int u;
            cin>>u;
            gh.Ans(u);
        }

    }
    
    return 0;
}