#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define f(i,n)			for(int i=0;i<n;i++)
#define fs(i,s,n)		for(int i=s;i<=n;i++)
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


// int MOD = 998244353;

// int inv(int a) {
//     int r = 1, t = a, k = MOD - 2;
//     while (k) {
//         if (k & 1) r = (long long) r * t % MOD;
//         t = (long long) t * t % MOD;
//         k >>= 1;
//     }
//     return r;
// }
 
 
void sm25official()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

#define N 1000005 
#define MAX 1e18

set<int> squares; 
set<int> s; 
void makesieve(){
    for (int i = 2; i < 10000; i++){ 
        squares.insert(i * i); 
  
        if (squares.find(i) != squares.end()) 
                continue; 
  
        int temp = i; 
  
        
        while (i * i <= MAX / temp)  
        { 
            temp *= (i * i); 

            s.insert(temp); 
        } 
    } 
    // cout<<squares.size()<<endl;
    // //999998
    // cout<<s.size()<<endl;
    //10196
}


int32_t main() {
    sm25official();

    makesieve();
    w(t){
        int n;
        cin>>n;
        int sum= (n%mod);
        
        for(auto i:s){
        	if(i==1){
        		continue;
        	}
        	if(i>n){
        		break;
        	}
        	else{
	        	int x= n/i;
	        	int value= (x%mod*i%mod)%mod;
	        	sum= ((sum%mod)+ (value%mod))%mod;
        	}
        }
        for(int i=2;i<=sqrt(n);i++){
            int j=i*i;
            int x= n/j;
            int value= (x%mod*j%mod)%mod;
            sum= ((sum%mod)+ (value%mod))%mod;
        }
        // for(auto i:squares){
        // 	if(i==1){
        // 		continue;
        // 	}
        // 	if(i>n){
        // 		break;
        // 	}
        // 	else{
	    //     	
        // 	}
        // }
        cout<<sum<<endl;
    }
    return 0;
}

