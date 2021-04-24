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

void BuildTree(int* a, int* tree, int s, int e, int i){
    if(s==e){
        tree[i]=0;
        return;
    }
    int mid= (s+e)/2;
    BuildTree(a, tree, s, mid, 2*i);
    BuildTree(a, tree, mid+1, e, 2*i +1);
    tree[i]= tree[2*i]+ tree[2*i +1];
}


void Update1(int* a, int* tree, int s, int e, int i, int idx){
    if(s>idx || e<idx) return;
    if(s==e){
        a[idx]= 2*a[idx] + 1;
        tree[i]++;
        return;
    }
    int mid= (s+e)/2;
    Update1(a, tree, s, mid, 2*i, idx);
    Update1(a, tree, mid+1, e, 2*i+1, idx);
    tree[i]= tree[2*i] + tree[2*i +1]; 
}

void Update2(int* a, int* tree, int s, int e, int i, int idx){
    if(s>idx || e<idx) return;
    if(s==e){
        a[idx]/=2;
        if(tree[i]>0)tree[i]--;
        return;
    }
    int mid= (s+e)/2;
    Update2(a, tree, s, mid, 2*i, idx);
    Update2(a, tree, mid+1, e, 2*i+1, idx);
    tree[i]= tree[2*i] + tree[2*i +1]; 
}

int FindTotalSetBits(int* tree, int s, int e, int i, int left, int right){
    if(left>e || right<s) return 0;

    if(left<=s && e<=right) return tree[i];

    int mid= (s+e)/2;

    int ans1= FindTotalSetBits(tree, s, mid, 2*i, left, right);
    int ans2= FindTotalSetBits(tree, mid+1, e, 2*i+1, left, right);
    return ans1+ans2;
}


int32_t main(){
    sm25official();
    int n, q;
    cin>>n>>q;

    int a[n]={0};

    int tree[4*n]={0};
    BuildTree(a, tree, 0, n-1, 1);

    while(q--){
        int ty;
        cin>>ty;
        if(ty==1){
            int idx;
            cin>>idx;
            idx--;
            Update1(a, tree, 0, n-1, 1, idx);
        }
        else if(ty==2){
            int idx;
            cin>>idx;
            idx--;
            Update2(a, tree, 0, n-1, 1, idx);
        }
        else{
            int left, right;
            cin>>left>>right;
            left--; right--;
            cout<<FindTotalSetBits(tree, 0, n-1, 1, left, right)<<endl;
        }
    }

    
    
    return 0;
}
