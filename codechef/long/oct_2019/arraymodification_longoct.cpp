#include <iostream>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<0<<endl;
        }
        else{
            if(n%2==0){
                if(k>=n){
                    ll x=k/n;
                    x=x%3;
                    ll r=k%n;
                    for(int i=0;i<x;i++){
                        for(int j=0;j<n;j++){
                            a[j]=a[j]^a[n-j-1];
                        }   
                    }
                    for(int i=0;i<r;i++){
                        a[i]=a[i]^a[n-i-1];
                    }
                }
                else{
                    for(int i=0;i<k;i++){
                        a[i]=a[i]^a[n-i-1];
                    }
                }
            }
            else{
                if(k>=n){
                    ll x=k/n;
                    x=x%3;
                    ll r=k%n;
                    if(x==0){
                        for(int i=0;i<3;i++){
                            for(int j=0;j<n;j++){
                                a[j]=a[j]^a[n-j-1];
                            }
                        }
                    }
                    else{
                        for(int i=0;i<x;i++){
                            for(int j=0;j<n;j++){
                                a[j]=a[j]^a[n-j-1];
                            }   
                        }
                    }
                    for(int i=0;i<r;i++){
                        a[i]=a[i]^a[n-i-1];
                    }
                }
                else{
                    for(int i=0;i<k;i++){
                        a[i]=a[i]^a[n-i-1];
                    }
                }
            }
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        
    }
}
