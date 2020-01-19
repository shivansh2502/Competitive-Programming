#include<bits/stdc++.h>
using namespace std;


int main(){
    int a[10];
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    int n=2;
    int m=5;
    int ans[2][5];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j]=a[i*m+j];
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    int maxrow=0;
    int maxcol=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=a[i][j];
        }
        if(sum>maxrow){
            maxrow=sum;
        }
    }
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i][j];
        }
        if(sum>maxcol){
            maxcol=sum;
        }
    }
    cout<<maxrow+maxcol<<endl;

}