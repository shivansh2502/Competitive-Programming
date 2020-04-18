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
    public:
        unordered_map<int , list<int>> adjlist;
    
    void addEdge(int u, int v, bool bidir= true){
        adjlist[u].push_back(v);
        if(bidir){
            adjlist[v].push_back(u);
        }
    }

    int dfsHelper(int u, int v, unordered_map<int, bool> &visited){
        visited[u]= true;
        if(u==v){
            return 0;
        }
        
        for(auto i: adjlist[u]){
            if(!visited[i]){
                int count= dfsHelper(i, v, visited);
                if(count!=-1){
                    return count+1;
                }
            }
        }
        return -1;
    }

    int dfs(int u, int v){
        unordered_map<int, bool> visited;
        visited[u]=true;
        int count=dfsHelper(u, v, visited);
        return count;
    }
};

bool comp(pair<int, pii> p1, pair<int, pii> p2){
    if(p2.second.first== p1.second.first){
        return p2.second.second>p1.second.second;
    }
    return p2.second.first<p1.second.first;
}
bool comp2(pair<int, pii> p1, pair<int, pii> p2){
    if(p2.second.second== p1.second.second){
        return p2.second.first<p1.second.first;
    }
    return p2.second.second>p1.second.second;
}

int32_t main(){
    sm25official();

    int n, k;
    cin>>n>>k;
    graph g;
    f(i, n-1){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    int countleaves=0;
    vector<pair<int, pii>> ve;
    for(auto i: g.adjlist){
        ve.push_back(mp(i.first, mp(g.dfs(1, i.first), i.second.size())));
    }
    sort(ve.begin(), ve.end(), comp);
    // for(auto i:ve){
    //     cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
    // }
    int ans1=0;
    unordered_map<int, int> selected;
    
    f(i, k){
        ans1+= ve[i].second.first;
        selected[ve[i].first]=0;

        for(auto j: g.adjlist[ve[i].first]){
            if(selected.count(j)){
                selected[ve[i].first]+=selected[j]+1;
            }
        }
        
        ans1-=selected[ve[i].first];
    }
    // for(auto i:selected){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    int ans2=0;
    sort(ve.begin(), ve.end(), comp2);
    //  for(auto i: ve){
    //     cout<<i.ff<<" "<<i.ss.ff<<" "<<i.ss.ss<<endl;
    // }
    selected.clear(); 
    f(i, k){
        ans2+= ve[i].second.first;
        selected[ve[i].first]=0;

        for(auto j: g.adjlist[ve[i].first]){
            if(selected.count(j)){
                selected[ve[i].first]+=selected[j]+1;
            }
        }
        
        ans2-=selected[ve[i].first];
    }

    cout<<max(ans1, ans2)<<endl;
    
    return 0;
}


