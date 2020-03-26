#include<bits/stdc++.h>
using namespace std;
#define ll long long

string ans;
void remove_duplicates(string s, int i){
    if(i==s.length()){
        return;
    }
   if(i-1>=0 && s[i]==s[i-1]){
       remove_duplicates(s, i+1);
   }
   else if(s[i]==s[i+1]){
        remove_duplicates(s, i+2);
   }
   else{
       ans+=s[i];
       remove_duplicates(s, i+1);
   }
}


int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
        ans.clear();
	    remove_duplicates(s, 0);
        for(int i=0;i<ans.length();i++){
            if(ans[i]==ans[i+1]){
                s=ans;
                ans.clear();
                remove_duplicates(s, 0);
                i=-1;
            }
        }
	    cout<<ans<<endl;
	}
	return 0;
}