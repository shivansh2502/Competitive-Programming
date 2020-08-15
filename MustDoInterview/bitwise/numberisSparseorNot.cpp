//a number is sparse if no two or more consecutive bits are set in that number

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int x=1;
	    int count=0;
	    bool flag=true;
	    while(x<=n){
	        if(x&n){
	            if(count==1){
	                cout<<0<<endl;
	                flag=false;
	                break;
	            }
	            else{
	                count=1;
	            }
	        }
	        else count=0;
	        
	        x=x<<1;
	    }
	    if(flag) cout<<1<<endl;
	}
	return 0;
}