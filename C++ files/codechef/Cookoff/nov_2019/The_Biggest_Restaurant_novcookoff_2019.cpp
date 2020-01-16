#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x[n];
        int h[n];
        for(int i=0;i<n;i++){
            cin>>x[i]>>h[i];
        }
        sort(x,x+n);
        sort(h,h+n);
        unordered_map<int,int> mp;
        int j=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                mp[x[i]]=h[j];
                j++;
            }
            else{
                mp[x[i]]=h[n-j];
            }
            // cout<<x[i]<<" "<<mp[x[i]]<<endl;
        }

        unsigned int area=0;
        for(int i=1;i<n;i++){
            int triangle=0;
            if(i%2!=0)
                triangle=(unsigned)(x[i]-x[i-1])*(unsigned)(mp[x[i]]-mp[x[i-1]]);
            else
                triangle=(unsigned)(x[i]-x[i-1])*(unsigned)(mp[x[i-1]]-mp[x[i]]);
            // cout<<triangle<<" ";
            area+=triangle;
            if(mp[x[i]]>mp[x[i-1]]){
                area+=2*(unsigned)(mp[x[i-1]]*(unsigned)(x[i]-x[i-1]));
            }
            else{
                area+=2*(unsigned)(mp[x[i]]*(unsigned)(x[i]-x[i-1]));
            }
            cout<<area<<" ";
        }
        cout<<endl;
        cout<<area<<endl;
    }
    return 0;
}