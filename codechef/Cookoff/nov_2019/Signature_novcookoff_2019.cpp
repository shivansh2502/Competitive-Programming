#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                a[i][j]=s[j]-'0';
            }
        }

        int b[n][m];
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                b[i][j]=s[j]-'0';
            }
        }
        int error=INT_MAX;
        for(int i=-(n-1);i<n;i++){
            for(int j=-(m-1);j<m;j++){
                int err=0;
                for(int k=0;k<n;k++){
                    for(int l=0;l<m;l++){
                        if(k-i<0 || k-i>=n || l-j<0 || l-j>=m){
                            // cout<<0;
                            if(a[k][l]!=0){
                                err++;
                            }
                        }
                        else{
                            if(b[k-i][l-j]!=a[k][l]){
                                err++;
                            }
                            // cout<<b[k-i][l-j];
                        }
                    }
                    // cout<<endl;
                }
                // cout<<endl;
                error=min(error,err);
            }
        }
        cout<<error<<endl;
    }
    return 0;
}