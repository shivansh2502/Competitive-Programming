#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s,w1,w2,w3;
        cin>>s>>w1>>w2>>w3;
        int count=0;
        if(w1+w2+w3<=s){
            count++;
            cout<<count<<endl;
        }
        else{
            if(w1+w2<=s){
                count+=2;
            }
            else{
                count++;
                if(w2+w3<=s){
                    count++;
                }
                else{
                    count+=2;
                }
            }
            cout<<count<<endl;
        }

    }
    return 0;
}