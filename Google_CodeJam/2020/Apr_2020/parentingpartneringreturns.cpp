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
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void shivansh2502()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
}

bool comp(pair<int, pii> a, pair<int, pii> b){
    return a.ff<b.ff;
}

int32_t main(){
    shivansh2502();
    int k=1;
    w(t){
        int n;
        cin>>n;
        vector<pair<int, pair<int,int>>> v;
        f(i, n){
            int s,e;
            cin>>s>>e;
            v.pb(mp(s,mp(e,i)));
        }
       
        sort(v.begin(), v.end(), comp);
        char s[1000];
        int sc=0, ec=0, sj=0, ej=0;
        bool flag=true;
        for(auto i:v){
            if(ec>i.ff){
                if(ej>i.ff){
                    // s="IMPOSSIBLE";
                    flag=false;
                    break;
                }
                else{
                    sj=i.ff;
                    ej=i.ss.ff;
                    s[i.ss.ss]='J';
                }
            }
            else{
                sc=i.ff;
                ec=i.ss.ff;
                s[i.ss.ss]='C';
            }
        }

        cout<<"Case #"<<k<<": ";
        if(flag){
            f(i, n){
                cout<<s[i];
            }
        }
        else{
            cout<<"IMPOSSIBLE";
        }
        cout<<endl;
        k++;
    }
    
    return 0;
}


