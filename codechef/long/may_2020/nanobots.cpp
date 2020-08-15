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
    int n, f;
    cin>>n>>f;
    int a[n][n];
    f(i, n){
        f(j, n){
            cin>>a[i][j];
        }
    }
    int k;
    cin>>k;

    vector<pair<char, int>> horhits;
    int hcelldes=0;
    f(i, n){
        int sum1=0;
        int celdes1=0;
        f(j, n){
            sum1+=a[i][j];
            if(sum1==f){
                celdes1+=j+1;
                break;
            }
            else if(sum1>f){
                sum1-=a[i][j];
                celdes1+=j;
                break;
            }
        }
        int sum2=0;
        int celdes2=0;
        for(int j=n-1;j>=0;j--){
            sum2+=a[i][j];
            if(sum2==f){
                celdes2+=n-j;
                break;
            }
            else if(sum2>f){
                sum2-=a[i][j];
                celdes2= n-j-1;
                break;
            }
        }
        if(celdes1>celdes2){
            hcelldes+=celdes1;
            horhits.pb(mp('L',i+1));
        }
        else if(celdes1<celdes2){
            hcelldes+=celdes2;
            horhits.pb(mp('R',i+1));
        }
        else{
            if(sum1>=sum2){
                hcelldes+=celdes1;
                horhits.pb(mp('L',i+1));
            }
            else{
                hcelldes+=celdes2;
                horhits.pb(mp('R',i+1));
            }
        }
    }

    vector<pair<char, int>> verhits;
    int vcelldes=0;
    f(j, n){
        int sum1=0;
        int celdes1=0;
        f(i, n){
            sum1+=a[i][j];
            if(sum1==f){
                celdes1=i+1;
                break;
            }
            else if(sum1>f){
                sum1-=a[i][j];
                celdes1=i;
                break;
            }
        }
        int sum2=0;
        int celdes2=0;
        for(int i=n-1;i>=0;i--){
            sum2+=a[i][j];
            if(sum2==f){
                celdes2=n-i;
                break;
            }
            else if(sum2>f){
                sum2-=a[i][j];
                celdes2=n-i-1;
                break;
            }
        }
        if(celdes1>celdes2){
            vcelldes+=celdes1;
            verhits.pb(mp('U',j+1));
        }
        else if(celdes1<celdes2){
            vcelldes+=celdes2;
            verhits.pb(mp('D',j+1));
        }
        else{
            if(sum1>sum2){
                vcelldes+=celdes1;
                verhits.pb(mp('U',j+1));
            }
            else{
                vcelldes+=celdes2;
                verhits.pb(mp('D',j+1));
            }
        }
    }
    


    if(vcelldes>=hcelldes){

        for(auto k: verhits){
            if(k.ff=='U'){
                int po=f;
                f(i, n){
                    int j=k.ss-1;
                    if(po>=a[i][j]){
                        po-=a[i][j];
                        a[i][j]=0;
                        if(po<=0){
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                int po=f;
                for(int i=n-1;i>=0;i--){
                    int j=k.ss-1;
                    if(po>=a[i][j]){
                        po-=a[i][j];
                        a[i][j]=0;
                        if(po<=0){
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }

        f(i, n){
            int po=f;
            f(j, n){
                if(a[i][j]==0 && po==f) continue;
                if(po>=a[i][j]){
                    po-=a[i][j];
                    if(po<=0 || j==n-1){
                        verhits.pb(mp('L', i+1));
                        po=f;
                    }
                }
                else{
                    verhits.pb(mp('L', i+1));
                    po=f;
                    po-=a[i][j];
                    if(j==n-1){
                        verhits.pb(mp('L', i+1));
                    }
                }
            }
        }

        cout<<verhits.size()<<endl;
        for(auto i:verhits){
            cout<<i.ff<<" "<<i.ss<<endl;
        }
    }
    else{
        for(auto k: horhits){
            if(k.ff=='L'){
                int po=f;
                f(i, n){
                    int j=k.ss-1;
                    if(po>=a[j][i]){
                        po-=a[j][i];
                        a[j][i]=0;
                        if(po<=0){
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                int po=f;
                for(int i=n-1;i>=0;i--){
                    int j=k.ss-1;
                    if(po>=a[j][i]){
                        po-=a[j][i];
                        a[j][i]=0;
                        if(po<=0){
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        // f(i,n){
        //     f(j, n){
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        f(j, n){
            int po=f;
            f(i, n){
                if(a[i][j]==0 && po==f) continue;
                if(po>=a[i][j]){
                    po-=a[i][j];
                    if(po<=0 || i==n-1){
                        horhits.pb(mp('U', j+1));
                        po=f;
                    }
                }
                else{
                    horhits.pb(mp('U', j+1));
                    po=f;
                    po-=a[i][j];
                    if(j==n-1){
                        horhits.pb(mp('U', j+1));
                    }
                }
            }
        }


        cout<<horhits.size()<<endl;
        for(auto i:horhits){
            cout<<i.ff<<" "<<i.ss<<endl;
        }
    }
    
    return 0;
}


