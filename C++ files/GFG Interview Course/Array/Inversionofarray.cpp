#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll merge(ll a[], ll s, ll mid, ll e){
    
    ll temp[200000];
    ll i=s, k=s;
    ll j=mid;
    ll invcount=0;
    while(i<=mid-1 && j<=e){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
            invcount+= (mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(ll i=s;i<=e;i++){
        a[i]=temp[i];
    }
    return invcount;
}

ll mergeSort(ll a[], ll s, ll e){
    if(s==e){
        return 0;
    }
    ll invcount=0;
    if(s<e){
        ll mid=(s+e)/2;
        invcount+=mergeSort(a, s, mid);
        invcount+=mergeSort(a, mid+1, e);
        invcount+=merge(a, s, mid+1, e);
    }
    return invcount;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<mergeSort(a,0, n-1)<<endl;
    }
    return 0;
}