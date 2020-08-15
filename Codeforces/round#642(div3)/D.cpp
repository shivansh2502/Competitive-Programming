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

bool comp(pair<int, pii> a1, pair<int, pii> a2){
    int len1= a1.ss.ss- a1.ss.ff+1;
    int len2= a2.ss.ss- a2.ss.ff+1;
    return len2>len1;
}


int32_t main(){
    sm25official();
    w(t){
        int n;
        cin>>n;
        int a[n+1]={0};
        
        unordered_map<int, set<int>> um;
        int s=1;
        int e=n;
        int len= e-s+1;
        um[len].insert(s);
        int val=1;
        set<int> se;
        se.insert(len);
        while(!se.empty()){
            int len=*se.rbegin();
            for(auto i:um[len]){
                if(len%2==0){
                    if(a[i+ (len/2)-1]==0){
                        a[i+ (len/2)-1]=val;
                        val++;
                        int len1=(len-1)/2;
                        int len2=len/2;
                        if(len1>0){
                            se.insert(len1);
                            um[len1].insert(i);
                        }
                        if(len2>0){
                            se.insert(len2);
                            um[len2].insert(i+ (len/2));
                        } 
                    }
                }
                else{
                    if(a[i+ (len/2)]==0){
                        a[i+ (len/2)]=val;
                        val++;
                        int len1=len/2;
                        int len2=len/2;
                        if(len1>0){
                            se.insert(len1);
                            um[len1].insert(i); 
                        } 
                        if(len2>0) {
                            se.insert(len2);
                            um[len2].insert(i+ (len/2)+1);
                        }
                    }
                }
            }
            se.erase(len);
        }

        fs(i, 1, n+1){
            cout<<a[i]<<" ";
        }
        cout<<endl;

        
    }
    
    return 0;
}


