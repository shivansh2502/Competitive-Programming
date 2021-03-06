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

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

template<typename T> 
class graph{
    unordered_map<T, list<pair<T,int>>> adjlist;
public:
    void addedge(T u, T v, int dist, bool bidir=true){
        adjlist[u].push_back(make_pair(v,dist));
        if(bidir){
            adjlist[v].push_back(make_pair(u,dist));
        }
    }

    void dijkstraalgo(T src){
        
        unordered_map<T,int> dist;
        for(auto i:adjlist){
            dist[i.first]=INT_MAX;
        }
        unordered_map<T, T> parent;

        dist[src]=0;
        set<pair<int, T>> s;
        s.insert(make_pair(0,src));
        
        while(!s.empty()){
            auto p=*(s.begin());
            T node= p.second;
            int nodeDist= p.first;
            s.erase(s.begin());

            for(auto childpair: adjlist[node]){
                if(nodeDist+ childpair.second < dist[childpair.first]){

                    T dest= childpair.first;
                    auto f= s.find(make_pair(dist[dest], dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    parent[dest]=node;

                    dist[dest]= nodeDist+ childpair.second;
                    s.insert(make_pair(dist[dest], dest));

                }
            }
        }
        for(auto d: dist){
            cout<<d.first<<" is located at distance "<< d.second<<" from the source"<<endl;
        }
        for(auto i: parent){
            cout<<i.first<<"->"<<i.second<<",";
            int k=i.second;
            while(parent.count(k)){
                cout<<parent[k]<<",";
                k=parent[k];
            }
            cout<<endl;
        }

    }

};



int32_t main(){
    sm25official();

    int n, m, k;
    cin>>n>>m>>k;
    
    f(i, m){
        int x, y, z;
        cin>>x>>y>>z;
        
    }

    
    return 0;
}


