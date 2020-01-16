#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    char c[100];
    cin>>c;
    // cout<<c;
    char ans[100];
    if(c[0]=='f'){

        for(int i=0;i<=2;i++){
            ans[i]=c[i];
        }
        ans[3]=':';
        ans[4]=ans[5]='/';
        int index=6;
        int i;
        for(i=3;c[i]!='r' && c[i+1]!='u';i++){
            ans[index++]=c[i];
        }
        ans[index++]='.';
        ans[index++]='r';
        ans[index++]='u';
        ans[index++]='/';

        for(i=i+2; c[i]!='\0';i++){
            ans[index++]=c[i];
        }
        ans[index]='\0';
        cout<<ans;
    }
    else if(c[0]=='h'){
        for(int i=0;i<=3;i++){
            ans[i]=c[i];
        }
        int index=4;
        ans[index++]=':';
        ans[index++]='/';
        ans[index++]='/';
        int i;
        for(i=4;c[i]!='r' && c[i+1]!='u';i++){
            ans[index++]=c[i];
        }
        ans[index++]='.';
        ans[index++]='r';
        ans[index++]='u';
        ans[index++]='/';

        for(i=i+2; c[i]!='\0';i++){
            ans[index++]=c[i];
        }
        ans[index]='\0';
        cout<<ans;
    }
    return 0;
}
