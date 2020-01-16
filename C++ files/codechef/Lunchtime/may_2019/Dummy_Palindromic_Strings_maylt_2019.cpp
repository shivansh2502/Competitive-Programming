#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int l=s.length();
        int p=0;
        for(int i=0;i<l-1;i++){
            for(int j=i+1;j<l;j++){
                if(s[i]==s[j]&& s[i]!=0 && s[j]!=0){
                    p++;
                    s[i]=0;
                    s[j]=0;
                    break;
                } 
            }
        }

        if(l%2==0){
            if(l-2*p==2){
                cout<<"DPS"<<endl;
            }
            else{
                cout<<"!DPS"<<endl;
            }
        }
        else{
            if(l-2*p==1 || l-2*p==3){
                cout<<"DPS"<<endl;
            }
            else{
                cout<<"!DPS"<<endl;
            }
        }
    }
    return 0;
}