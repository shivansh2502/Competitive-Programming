#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    string a;
	    string b;
	    cin>>a>>b;
	    int maxl=0;
	    for(int i=0;i<m;i++){
	        int l=0;
            int k=i;
	        for(int j=0;j<n;j++){
	            if(a[k]==b[j]){
	                l++;
	                k++;
	            }
	            else{
	                maxl= max(l, maxl);
	                l=0;
                    if(k!=i){
                        k=i;
                        j--;
                    }
                    if(k==m){
                        break;
                    }
	            }
	        }
	        maxl= max(l, maxl);
	    }
	    cout<<maxl<<endl;
	}
	return 0;
}