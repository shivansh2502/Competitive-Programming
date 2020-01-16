#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxxor=a[0];
    for(int i=0;i<n;i++){
        int axor=0;
        for(int j=i;j<n;j++){
            axor=axor^a[j];
            maxxor=max(axor ,maxxor);
        }
    }
    cout<<maxxor<<endl;
    return 0;
}
