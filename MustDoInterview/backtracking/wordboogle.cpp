#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
 {

     

    //using hashmap 
    /* 
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<string> dict(n);
	    for(int i=0;i<n;i++) cin>>dict[i];
	    
	    int a, b;
	    cin>>a>>b;
	    vector<char> boog(a*b);
	    for(int i=0;i<a*b;i++) cin>>boog[i];
	    
	    unordered_map<char, int> hash;
        unordered_map<char, int> hash1;
	    for(int i=0;i<a*b;i++) hash[boog[i]]++;

        hash1=hash;
	    
	    set<string> s;
	    for(int i=0;i<n;i++){
	        bool flag=true;
	        for(int j=0;j<dict[i].length();j++){
	            if(hash1.count(dict[i][j]) && hash1[dict[i][j]]>0){
	                hash1[dict[i][j]]--;
	            }
	            else{
	                flag=false;
	                break;
	            }
	        }
	        if(flag){
	            s.insert(dict[i]);
	        }
	        hash1= hash;
	       
	    }
	    if(s.size()==0){
	        cout<<-1<<endl;
	    }
	    else{
    	    for(auto &i:s){
    	        cout<<i<<" ";
    	    }
    	    cout<<endl;
	    }
	    
	}
    */
	return 0;
}