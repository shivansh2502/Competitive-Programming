#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=0;
    int currentno=0;
    for(int i=0;i<n;i++){
        cout<<currentno<<endl;
        if(s[i]=='2' || s[i]=='3' || s[i]=='5' || s[i]=='7'){
            currentno=0;
            count++;
        }
        else{
            currentno=currentno*10 + (s[i]-'0');
            if(currentno==11 || currentno==13 || currentno==17 || currentno==19 || currentno==23 || currentno==29){
                count++;
                currentno=0;
                continue;
            }
            else if(currentno%2!=0 &&
                    currentno%3!=0 &&
                    currentno%5!=0 &&
                    currentno%7!=0 &&
                    currentno%11!=0 &&
                    currentno%13!=0 &&
                    currentno%17!=0 &&
                    currentno%19!=0 &&
                    currentno%23!=0 &&
                    currentno%29!=0 ){
                count++;
                currentno=0;
                continue;
             }

        }
    }
    cout<<count<<endl;
    return 0;
}