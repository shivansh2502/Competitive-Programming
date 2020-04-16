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

int32_t main(){
    shivansh2502();

    int k=1;
    w(t){
        string s;
        cin>>s;
        int n=s.length();
        vector<pair<int,int>> v;
        int currentvalue=-1;
        int currentcount=0;
        f(i, n){
            if(s[i]-'0'==currentvalue){
                currentcount++;
                if(i==n-1) v.pb(mp(currentvalue, currentcount));
            }
            else{
                if(i!=0) v.pb(mp(currentvalue, currentcount));
                currentvalue=s[i]-'0';
                currentcount=1;
                if(i==n-1) v.pb(mp(currentvalue, currentcount));
            }
        }
        
        string ans;
        int start=0;

        f(i, v.size()){
            int x=v[i].ff;
            if(i==0){
                f(j,x){
                    ans+='(';
                }         
            }
            f(j, v[i].ss){
                ans+= x+'0';
            }
            if(i!=v.size()-1){
                if(v[i+1].ff<x){
                    f(j,x-v[i+1].ff){
                        ans+=')';
                    }
                }
                else{
                    f(j,v[i+1].ff-x){
                        ans+='(';
                    }
                }
            }
            else{
                f(j,x){
                    ans+=')';
                }
            }
        }
        // for(auto i:v){
        //     int x=i.ff;
        //     f(j,x){
        //        ans+='(';
        //     }
        //     f(j, i.ss){
        //         ans+= x+'0';
        //     }
        //     f(j,x){
        //         ans+=')';
        //     }
        // }
        cout<<"Case #"<<k<<": "<<ans<<endl;
        k++;
    }
    
    return 0;
}


