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

map<char, set<char> > child;

void dfshelper(char src, list<char> &v, map<char, bool>& visited){
    visited[src]=true;
    for(auto i: child[src]){
        if(!visited[i]){
            dfshelper(i, v, visited);
        }
    }
    v.push_front(src);
    return;
}

int32_t main(){
    sm25official();
    int te=1;
    w(t){
        child.clear();
        cout<<"Case #"<<te<<": ";
        int r,c;
        cin>>r>>c;
        char a[r][c];
        map<char, bool> visited;
        f(i, r){
            f(j, c){
                cin>>a[i][j];
                visited[a[i][j]]=false;

            }
        }

        bool f=true;
        for(int i=r-1;i>0;i--){
            f(j, c){
                if(a[i-1][j]!=a[i][j]){
                    if(child[a[i-1][j]].count(a[i][j])){
                        f=false;
                        break;
                    }
                    child[a[i][j]].insert(a[i-1][j]);
                }
            }
            if(!f) break;
        }
        if(!f){
            cout<<-1<<endl;
        }
        else{
            
            list<char> v;
            for(auto i:visited){
                if(!i.ss){
                    dfshelper(i.ff, v, visited);
                }
            }
        
            for(auto i:v){
                cout<<i;
            }
            cout<<endl;
        }
        te++;
    }
    
    return 0;
}


