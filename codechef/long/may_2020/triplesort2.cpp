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
        int n, k;
        cin>>n>>k;
        n++;
        int p[n];
        for(int i=1;i<n;i++){
            cin>>p[i];
        }
        vector<int> s;
        unordered_set<int> se;
        se.reserve(n);
        s.reserve(n);
        for(int i=1;i<n;i++){
            s[p[i]]=i;
            if(p[i]!=i){
                se.insert(i);
            }
        }
        vector<pair<int, pii>> v;
        bool flag=true;
        for(int i=1;i<n;i++){
            if(i!=p[i]){
                int index1=s[i];
                int index2=i;
                int val=p[i];
                p[i]=i;
                if(index1==val){
                    int index=-1;
                    for(auto& j:se){
                        if(p[j]!=j && j!=index2 && j!=index1){
                            index=j;
                            break;
                        }
                    }
                    if(index==-1){
                        flag=false;
                        break;
                    }
                    
                    p[val]=p[index];
                    s[p[val]]= val;
                    p[index]= val;
                    s[p[index]]=index;
                    v.push_back(mp(index2,mp(index, index1)));
                }
                else{
                    p[index1]=p[val];
                    s[p[index1]]= index1;
                    p[val]=val; 
                    s[p[val]]=val;
                    v.push_back(mp(index2,mp(val, index1)));
                }
                s[p[i]]=p[i];
            }
            // fs(i, 1, n) cout<<p[i]<<" ";
            // cout<<endl;
        }

        if(flag && k>=v.size()){
            cout<<v.size()<<endl;
            for(auto& i: v){
                cout<<i.ff<<" "<<i.ss.ff<<" "<<i.ss.ss<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
    }
    
    return 0;
}


