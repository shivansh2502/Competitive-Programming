#include<bits/stdc++.h>
using namespace std;
#define ll long long

int countsetbits(int n){
    int count=0;
    while(n!=0){
        count++;
        n= n&(n-1);
    }
    return count;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int totalsetbits=0;
	    for(int i=1;i<=n;i++){
	        totalsetbits+=countsetbits(i);
	    }
	    cout<<totalsetbits<<endl;
	}
	return 0;
}