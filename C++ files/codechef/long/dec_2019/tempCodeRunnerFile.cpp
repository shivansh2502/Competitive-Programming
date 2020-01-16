#include<bits/stdc++.h>
using namespace std;
#define ll long long

// ll add(string a1, string b1){
//     ll count=0;
    
//     bool flag=false;
//     for(unsigned ll i=0;i<b1.length();i++){
//         if(b1[i]!='0'){
//             flag=true;
//             break;
//         }
//     }

//     while(flag){
//         auto u = bitset<1000>(a1) ^ bitset<1000>(b1);
//         auto v = bitset<1000>(a1) & bitset<1000>(b1);
//         v=v<<1;

//         count++;
//         a1=u.to_string();
//         b1=v.to_string();

//         ll result = v.count();
//         if(result==0){
//             flag=false;
//         }
//     }
//     return count;
// }

int main(){
    ll t;
    cin>>t;
    while(t--){
        string a;
        string b;
        cin>>a>>b;
        auto x=bitset<10000>(b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.length()<b.length()){
            for(ll i=a.length();i<b.length();i++){
                a+='0';
            }
        }
        else{
             for(ll i=b.length();i<a.length();i++){
                b+='0';
            }
        }
        ll m= a.length();
        ll ans=0;
        // cout<<a<<" "<<b<<endl;
        for(ll i=0;i<m;i++){
            ll count=0;
            if(a[i]=='1' && b[i]=='1'){
                ll j=i;
                for(j=i;j<m;j++){
                    if(a[j]=='0' && b[j]=='0'){
                        break;
                    }
                    count++;
                }
                i=j;
                ans+=count;
            }
        }
        if(x.count()>0){
            cout<<ans+1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}