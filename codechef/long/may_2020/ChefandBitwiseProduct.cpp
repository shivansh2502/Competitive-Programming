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
 
 
void shivansh2502(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

#define M 64

void func(vector<int> v, int j, int sum, set<int>& possible, int r, int an){
    
    if(j==v.size()){
        possible.insert(sum);
        return;
    }
    
    if(sum+powl(2, v[j])<=r ) func(v, j+1, sum+ powl(2, v[j]), possible, r, an);

    func(v, j+1, sum, possible, r, an);
    return;
}

int32_t main(){
    shivansh2502();

    w(t){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        int an = x&y;
        if(x==0 || y==0){
            cout<<0<<endl;
            continue;
        }
        int ans=x|y;
        if(r >= ans ){
            cout<< ans <<endl;
        }
        else if(r<an){
            cout<<0<<endl;
        }
        else{
            // vector<int> v;
            // bitset<M> xs(x);
            // bitset<M> ys(y);
            // set<int> possible;
            // f(i, M){
            //     if(xs.test(i) || ys.test(i)) v.pb(i);
            // }
            // func(v, 0, 0, possible, r, an);
            // int mul=0;
            // int val=0;
            // // for(auto i:possible) cout<<i<<" ";
            // // cout<<endl;
            // for(auto i:possible){
            //     if(i>=l){
            //         int m= (x&i)*(y&i);
            //         if(m>mul){
            //             mul=m;
            //             val=i;
            //         }
            //     }
            // }
            // cout<<val<<endl;
            int dif= ans - r;
            int op= (ans) & (dif);
            // cout<<dif<<endl;
            // cout<<op<<endl;
            if(op==dif){
                int a1= ans- dif;
                int val= (x&a1)* (y&a1);
                if(val==0){
                    int ma=  (log2(dif))+1 ;
                    bitset<M> xs(ans);
                    int maxval=0, ansfinal=0;
                    fs(i, ma, M){
                        if(xs.test(i)){
                            xs[i]=0;
                            int ans= xs.to_ullong();
                            int val= (x&ans)* (y&ans);
                            if(val==0){
                                xs[i]=1;
                            }
                            else{
                                if(val>maxval){
                                    maxval=val;
                                    ansfinal= ans;
                                }
                            }
                        }
                    }
                    if(maxval==0){
                        cout<<0<<endl;
                    }
                    else cout<<ansfinal<<endl;
                }
                else{
                    cout<<a1<<endl;
                }
            }
            else{
                int ma=  (log2(dif))+1 ;
                bitset<M> xs(ans);
                int maxval=0, ansfinal=0;
                fs(i, ma, M){
                    if(xs.test(i)){
                        xs[i]=0;
                        int ans1= xs.to_ullong();
                        int val= (x&ans1)* (y&ans1);
                        if(val==0){
                            xs[i]=1;
                        }
                        else{
                            if(val>maxval){
                                maxval=val;
                                ansfinal= ans1;
                            }
                        }
                        
                    }
                }
                if(maxval==0){
                    cout<<0<<endl;
                }
                else cout<<ansfinal<<endl;

            }
        }

    }

    
    return 0;
}


