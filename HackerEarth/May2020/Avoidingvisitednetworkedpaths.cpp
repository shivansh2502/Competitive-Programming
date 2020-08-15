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


int x= 212072634227239451;
int path(int a[][1003], int total, int i, int j, int n, int m){


    if(i>=n || i<0 || j>=n || j<0){
        return 0;
    }
    if(a[i][j]==x){
        return 0;
    }
    if(i==n-1 && j==m-1){
        if(total%x==0) return 0;
        else return 1;
    }
    
    total*=a[i][j];
    // cout<<i<<","<<j<<"->"; 
    // cout<<total<<endl;
    int count1= path(a, total, i+1, j, n, m);
    int count2= path(a, total, i, j+1, n, m);
    int count= count1+ count2;
    return count;
}

int numberOfPaths(int m, int n){ 
    // We have to calculate m+n-2 C n-1 here 
    // which will be (m+n-2)! / (n-1)! (m-1)! 
    int path = 1; 
    for (int i = n; i < (m + n - 1); i++) { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
} 

int32_t main(){
    sm25official();

    int n, m;
    cin>>n>>m;
    int a[n][1003];
    f(i, n){ 
        f(j, m){ 
            cin>>a[i][j]; 
        }
    }
 
    int total=1;
    int count= path(a, total, 0, 0, n, m);
    cout<<count<<endl;
    
    return 0;
}


