#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

bool func(int s, int e, int a[], int prime[], int parrsize, int m){
    if(m==0 && s==e){
        return true;
    }
    else if(m==0 && s!=e){
        return false;
    }

    if(s<0 || s>e){
        return false;
    }
    else{
        for(int i=0;i<parrsize;i++){
            if(a[s]%prime[i]==0){
                bool ans1= func(s+ prime[i], e, a, prime, parrsize, m-1);
                bool ans2= func(s- prime[i], e, a, prime, parrsize, m-1);
                if(ans1 || ans2){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[100000];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;

        int prime[]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
        int parrsize= sizeof(prime)/ sizeof(int);

        bool ans = func(0, n-1, a, prime, parrsize, m);  

        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;      
    }
    return 0;
}
