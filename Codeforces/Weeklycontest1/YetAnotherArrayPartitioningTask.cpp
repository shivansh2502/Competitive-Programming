#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll  n,m,k;
    cin>>n>>m>>k;
    ll  a[n];
    for(ll  i=0;i<n;i++){
        cin>>a[i];
    }
    ll  total_max=-1;
    ll  extraelement=-1;
    for(ll  i=0;i<k;i++){
        ll  current_max=0;
        ll  l=0;
        for(ll  j=0;j<k;j++){
            vector<ll > v;
            ll  itr;
            if(i==j){
                itr=((n/k)+n%k);
            }
            else{
                itr=(n/k);
            }
            while(itr--){
                v.push_back(a[l]);
                l++;
            }
            sort(v.begin(), v.end(), greater<ll >());
            for(ll  o=0;o<m;o++){
               current_max+=v[o]; 
            }
        }
        if(current_max>total_max){
            total_max=current_max;
            extraelement=i;
        }
    }

    cout<<total_max<<endl;

    ll  itr = 0;
    for (ll  i = 0; i < k - 1; i++) {
        if(i==extraelement){
            itr+=(n / k + n % k);
        }
        else{
            itr+=n/k;
        }
        
        cout << itr << " ";
    }
    cout << endl;
    
    return 0;
}