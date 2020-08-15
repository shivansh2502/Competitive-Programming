#include<bits/stdc++.h>
using namespace std;
#define int long long


// using recursion
int minimumjumps(int a[], int n){

    if(n==1) return 0;

    int res= INT_MAX;
    for(int i=n-2;i>=0;i--){
        if(i+a[i]>=n-1){
            int smallans= minimumjumps(a, i+1);
            if(smallans!= INT_MAX) res= min(res, smallans+1);
        }
    }
    return res;
}

int minjumps(int a[], int n){
    
}

int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	int t;
	cin>>t;
	while(t--){
        int n;
	    cin>>n;
        int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];

	    cout<<minimumjumps(a, n)<<endl;
	}
	return 0;
}