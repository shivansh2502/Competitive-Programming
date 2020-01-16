#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int current_max=0;
	    int total_max=INT_MIN;
	    for(int i=0;i<n;i++){
	        current_max+=a[i];
	        total_max=max(current_max, total_max);
	        if(current_max<0){
	            current_max=0;
	        }
	       // total_max=max(current_max, total_max);
	    }
	    cout<<total_max<<endl;
	}
	return 0;
}