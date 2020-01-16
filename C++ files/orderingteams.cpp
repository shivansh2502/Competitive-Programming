#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a[3],b[3],c[3];
        int sum1[3];
        for(int i=0;i<3;i++){
            cin>>a[i]>>b[i]>>c[i];
            sum1[i]=a[i]+b[i]+c[i];
        }
        sort(a,a+3);
        sort(b,b+3);
        sort(c,c+3);
        sort(sum1,sum1+3);
        int sum2[3];
        int count=0;
        for(int i=0;i<3;i++){
            sum2[i]=a[i]+b[i]+c[i];
            if(sum2[i]==sum1[i]){
                if(i>0 && sum1[i]==sum1[i-1]){
                    count=0;
                }
                else{
                    count++;
                }
            }
        
        }
        if(count==3){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}