#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[10000];
        int count=1;
        for(int i=0;i<n;i++){
            cin>>p[i];
        }

        for(int i=1;i<n;i++){
            bool flag=true;
            for(int j=i-1;j>=i-5 && j>=0;j--){
                if(p[i]>=p[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}