#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ask(ll a, ll b){
    cout<<1<<" "<<a<<" "<<b<<endl;
    fflush(stdout);
    ll x;
    cin>>x;
    return x;
}

int main() {
    ll N;
    cin>>N;
    ll l1,r1,l2,r2;
    l1=r1=l2=r2=LLONG_MAX;
    ll left=1;
    ll right=N;

    while(left<=right){
        ll mid=(left+right)/2;
        if(ask(1,mid)<2){
            left=mid+1;
        }
        else{
            right=mid-1;
            l2=min(l2,mid);
        }
    }

    r2=left=l2;
    right=N;
    while(left<=right){
        ll mid=(left+right)/2;
        if(ask(mid,N)>0){
            left=mid+1;
            r2=max(r2,mid);
        }
        else{
            right=mid-1;
        }
    }

    left=1;
    right=l2-1;

    while(left<=right){
        ll mid=(left+right)/2;
        if(ask(1,mid)>0){
            right=mid-1;
            l1=min(l1,mid);
        }
        else{
            left=mid+1;
        }
    }

    r1=left=l1;
    right=l2-1;
    while(left<=right){
        ll mid=(left+right)/2;
        if(ask(mid,l2-1)>0){
            left=mid+1;
            r1=max(r1,mid);
        }
        else{
            right=mid-1;
        }
    }

    cout<<2<<" "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
    fflush(stdout);
    return 0;
}
