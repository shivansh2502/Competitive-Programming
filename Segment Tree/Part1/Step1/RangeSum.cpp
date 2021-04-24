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

void buildSegmentTree(int* a, int* tree, int s, int e, int idx){
    
    if(s==e){
        tree[idx]=a[s];
        return;
    }

    int mid= (s+e)/2;
    buildSegmentTree(a, tree, s, mid, 2*idx);
    buildSegmentTree(a, tree, mid+1, e, 2*idx + 1);
    tree[idx]= tree[2*idx]+ tree[2*idx + 1];
}

void valueUpdateQuery(int* tree, int s, int e, int i, int v, int idx){
    if(s>i || e<i) return;

    if(s==e & s==i){
        tree[idx]=v;
        return;
    }
    int mid= (s+e)/2;
    valueUpdateQuery(tree, s, mid, i, v, 2*idx);
    valueUpdateQuery(tree, mid+1, e, i, v, 2*idx+1);
    tree[idx]= tree[2*idx] + tree[2*idx +1];
}

int findSum(int* tree, int s, int e, int l, int r, int idx){
    if(l>e || r<s) return 0;

    if(s>=l && e<=r){
        return tree[idx];
    }

    int mid=(s+e)/2;
   
    return findSum(tree, s, mid, l, r, 2*idx) + findSum(tree, mid+1, e, l, r, 2*idx +1);
}

int32_t main(){
    sm25official();

    int n, m;
    cin>>n>>m;
    int a[n];
    f(i, n) cin>>a[i];

    int tree[4*n]={0};
    buildSegmentTree(a, tree, 0, n-1, 1);
    
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int i, v;
            cin>>i>>v;
            valueUpdateQuery(tree, 0, n-1, i, v, 1);
           
        }else{
            int l, r;
            cin>>l>>r;
            r--;
            cout<<findSum(tree, 0, n-1, l, r, 1)<<endl;
        }
    }
    
    
    return 0;
}
