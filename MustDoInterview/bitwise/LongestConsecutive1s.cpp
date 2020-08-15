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
	    int count=0;
	    while(n!=0){
	        count++;
	        n= n&(n<<1);
	    }
	    cout<<count<<endl;
	}
	return 0;
}