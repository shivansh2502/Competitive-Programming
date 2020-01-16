#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        unordered_map<int,int> um;
        vector<int> v(k+1);
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            um[a[i]]++;
            v[k]=a[i];

            auto it= find(v.begin(),v.end()-1, a[i]);

            for(int j=distance(v.begin(),it)-1;j>=0;j--){
                if(um[v[j]] < um[v[j+1]]){
                    swap(v[j],v[j+1]);
                }
                else if(um[v[j]]==um[v[j+1]] && (v[j] > v[j+1])){
                    swap(v[j],v[j+1]);
                }
                else{
                    break;
                }
                
            }

            for(int j=0;j<k && v[j]!=0;j++){
                cout<<v[j]<< " ";
            }
        }
        cout<<endl;
    }
    return 0;
}