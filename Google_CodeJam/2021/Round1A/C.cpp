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

int findlength(int n){
    int l=0;
    int temp= n;
    while(temp>0){
        l++;
        temp/=10;
    }
    return l;
}

int32_t main(){
    sm25official();
    int ittr=1;
    w(t){
        cout<<"Case #"<<ittr<<": ";

        int n;
        cin>>n;
        vector<string> v(n);
        f(i, n) cin>>v[i];

       
        int ans=0;

        for(int i=0;i<n;i++){
            int l=v[i].length();

            
            if(i>0){
                if(v[i-1]>=v[i]){
                    int l1= v[i-1].length();
                    int temp= v[i];
                    if (l1==l){
                        temp*=10;
                        ans++;
                    }
                    else{
                        temp*=powl(10, l1-l);
                        bool flag=false;
                        for(int j=1;j<=l;j++){
                            int q1= v[i-1]/powl(10, l1-j);
                            int q2= v[i]/powl(10, l-j);
                            if(q1>q2){
                                temp*=10;
                                ans+=l1-l+1;
                                flag=true;
                                break;
                            }
                            else if(q2>q1){
                                ans+=l1-l;
                                flag=true;
                                break;
                            }
                        }

                        if(!flag){
                            int num=0;
                            int temp1=v[i-1];
                            int count=0;
                            while(count<l1-l){
                                num*=10;
                                num+=temp1%10;
                                temp1/=10;
                                count++;
                            }
                            
                            if(num== powl(10, l1-l)-1){
                                temp*=10;
                                ans+= l1-l+1;
                            }
                            else{
                                temp= v[i-1]+1;
                                ans+=l1-l;
                            }
                        }  
                    }
                    v[i]=temp;
                }
            }
        }
        f(i, n){
            cout<<v[i]<<endl;
        }
        cout<<ans<<endl;
        
        ittr++;
    }
    
    return 0;
}


