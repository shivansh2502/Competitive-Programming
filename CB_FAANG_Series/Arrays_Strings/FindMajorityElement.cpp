// find the majority elements which occur more than n/3 times in  O(n) time and O(1) space complexity
// Boyer Moore's Majority Voting Algorithm


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
 
 

vector<int> MajorityElements(int a[], int n){
    vector<int> ans;

    int element1=a[0];
    int count1=1;
    
    int element2=0;
    int count2=0;

    for(int i=1;i<n;i++){
        if(a[i]==element1){
            count1++;
        }
        else if(a[i]==element2){
            count2++;
        }
        else if(count1==0){
            element1=a[i];
            count1=1;
        }
        else if(count2==0){
            element2=a[i];
            count2=1;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1=count2=0;
    for(int i=0;i<n;i++){
        if(a[i]==element1) count1++;
        if(a[i]==element2) count2++;
    }
    if(count1>n/3) ans.push_back(element1);
    if(count2>n/3) ans.push_back(element2);
    
    return ans;
}

int32_t main(){
    
    int n;
    cin>>n;
    int a[n];
    f(i, n) cin>>a[i];

    vector<int> v= MajorityElements(a, n);
    if(v.size()==0){
        cout<<"No Majority Elements"<<endl;
    }
    else{
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}


