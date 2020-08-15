#include<bits/stdc++.h>
using namespace std;

int findelement(int *a, int k, int n){
    int e=n-1;
    int s=0;
    
    while(s<=e){
        int mid= (s+e)/2;
        if(a[mid]==k){
            return mid;
        }
        if(a[mid]<=a[e]){
            if(k> a[mid] && k<=a[e]) s= mid+1;
            else e= mid-1;
        }
        else{
            if(k>= a[s] && k<a[mid]) e= mid-1;
            else s=mid+1;
        }
    }
    return -1;
}



int32_t main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        int k;
        cin>>k;
        int index= findelement(a, k, n);
        cout<<index<<endl;
    }
    
    return 0;
}


