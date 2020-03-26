#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n=s.length();
	    
	    int maxcount=1;
	    int startindex=0;
	    for(int i=1;i<n;i++){
            int count=1;
	        int si=0;
	        for(int j=1;i-j>=0 && i+j<n;j++){
	            if(s[i-j]==s[i+j]){
	                count+=2;
                    si=i-j;
	            }
	            else break;
	        }
            if(count>maxcount){
	            maxcount=count;
	            startindex=si;
	        }
            count=1;
            si=0;
	        for(int j=0;i-j-1>=0 && i+j<n;j++){
	            if(s[i-j-1]== s[i+j]){
	                if(j==0)    count++;
	                else count+=2;
                    si=i-j-1;
	            }
	            else break;
	        }
	        if(count>maxcount){
	            maxcount=count;
	            startindex=si;
	        }
            // for(int j=startindex;j<=(startindex+maxcount);j++){
	        //     cout<<s[j];
	        // }
	        // cout<<endl;
	    }
	    
	    for(int j=startindex;j<(startindex+maxcount);j++){
	        cout<<s[j];
	    }
	    cout<<endl;
	}
	return 0;
}