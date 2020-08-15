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

 
int lps[10005][30];

int KMPSearch(string& pat, string& txt, int k) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
    int ans=0;
  
    int i = 0; 
    int j = 0; 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            ans++;
            j = lps[k][j - 1]; 
        } 
  
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[k][j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return ans;
} 
 
void computeLPSArray(string& pat, int M, int k){ 
    int len = 0; 
    lps[k][0] = 0; 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[k][i] = len; 
            i++; 
        } 
        else{ 
            if (len != 0) { 
                len = lps[k][len - 1]; 
            } 
            else{ 
                lps[k][i] = 0; 
                i++; 
            } 
        } 
    } 
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
        string a, b;
        cin>>a>>b;
        int n;
        cin>>n;
        vector<pair<string , int>> vec;
        f(i, n){
            string s;
            cin>>s;
            int k;
            cin>>k;
            vec.pb(mp(s, k));
            computeLPSArray(s, s.length(),i);
        }
        int lena= a.length();
        int lenb= b.length();
        int ans=0;
        // string ansstr;
        f(i,lena+1){
            f(k,lenb){
                string first= a.substr(0,i);
                string second= b.substr(k, lenb-k+1);
                string result= first+second;
                int currans=0;
                f(o, n){
                    int cnt=KMPSearch(vec[o].ff, result, o);
                    currans += (cnt*vec[o].ss);
                }
                // if(currans> ans){
                //     ansstr= result;
                // }
                ans= max(ans, currans);
            }
        }
        // cout<<ansstr<<endl;
        cout<<ans<<endl;
    }
    
    return 0;
}


