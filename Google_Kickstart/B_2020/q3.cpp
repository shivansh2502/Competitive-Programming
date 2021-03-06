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
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
}

int m= 1e9;

void generate(string s, int i, int e, unordered_map<int, int> um, int &x, int &y){
    
    for(int j=i;j<=e;j++){
        if(s[j]>='2' && s[j]<='9'){
            int curx=x;
            int cury=y;
            generate(s, j+2, um[j+1]-1, um, x, y);
            int val= s[j]-'0';
            int valx= x- curx;
            int valy= y- cury;
            f(l, val-1){
                if(x+valx>m){
                    x-=m;
                    x+=valx;
                }
                else if(x+valx<1){
                    x+=m;
                    x+=valx;
                }
                else{
                    x+=valx;
                }
                if(y+valy>m){
                    y-=m;
                    y+=valy;
                }
                else if(y+valy<1){
                    y+=m;
                    y+=valy;
                }
                else{
                    y+=valy;
                }
            }
            j+=um[j+1]-j;
        }
        else{
            if(s[j]== 'W'){
                if(x==1) x=m;
                else x= x-1;
            }
            else if(s[j]=='E'){
                if(x==m) x=1;
                else x=(x+1);
            }
            else if(s[j]=='N'){
                if(y==1) y=m;
                else y= y-1;
            }
            else if(s[j]=='S'){
                if(y==m) y=1;
                else y=(y+1);
            }
        }
    }
    return;
}

int32_t main(){
    sm25official();
    int k=1;
    w(t){
        cout<<"Case #"<<k<<": ";
        string s;
        cin>>s;

        unordered_map<int, int> um;
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                int x= st.top();
                um[x]= i;
                st.pop();
            }
        }
        int x=1;
        int y=1;
        generate(s, 0, s.length()-1,um, x, y);
        
        cout<<x<<" "<<y<<endl;
        k++;
    }
    return 0;
}


