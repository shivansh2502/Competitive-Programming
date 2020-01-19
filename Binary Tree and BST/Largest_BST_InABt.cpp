#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int pre[n];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int currentlength=1;
    int maxlength=0;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            currentlength++;
            if(currentlength>maxlength){
                maxlength=currentlength;
            }
        }
        if(a[i]<a[i-1]){
            currentlength=1;
        }
    }
    cout<<maxlength<<endl;
    return 0;
}