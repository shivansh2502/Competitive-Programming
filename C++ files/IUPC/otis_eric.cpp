#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll  t;
    cin>>t;
    while(t--){
        ll  n;
        cin>>n;
        ll  k=n%12;
        ll  ans=n;
        switch (k)
        {
        case 1:
            cout<<ans+11<<endl;
            cout<<"Blue"<<endl;
            break;
        case 2:
            cout<<ans+9<<endl;
            cout<<"Yellow"<<endl;
            break;
        case 3:
            cout<<ans+7<<endl;
            cout<<"Red"<<endl;
            break;
        case 4:
            cout<<ans+5<<endl;
            cout<<"Red"<<endl;
            break;
        case 5:
            cout<<ans+3<<endl;
            cout<<"Yellow"<<endl;
            break;
        case 6:
            cout<<ans+1<<endl;
            cout<<"Blue"<<endl;
            break;
        case 7:
            cout<<ans-1<<endl;
            cout<<"Blue"<<endl;
            break;
        case 8:
            cout<<ans-3<<endl;
            cout<<"Yellow"<<endl;
            break;
        case 9:
            cout<<ans-5<<endl;
            cout<<"Red"<<endl;
            break;
        case 10:
            cout<<ans-7<<endl;
            cout<<"Red"<<endl;
            break;
        case 11:
            cout<<ans-9<<endl;
            cout<<"Yellow"<<endl;
            break;
        case 0:
            cout<<ans-11<<endl;
            cout<<"Blue"<<endl;
            break;
        }
    }
    return 0;
}