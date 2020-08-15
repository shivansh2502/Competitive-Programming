#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    queue<char> q;
	    map<char, int> m;
	    for(int i=0;i<n;i++){
	        char x;
	        cin>>x;
	        m[x]++;
            q.push(x);
            while(!q.empty()){
                if(m[q.front()]>1) q.pop();
                else{
                    cout<<q.front()<<" ";
                    break;
                }
            }
            if(q.empty()) cout<<-1<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}