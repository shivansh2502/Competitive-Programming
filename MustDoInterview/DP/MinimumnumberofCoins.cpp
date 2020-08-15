//  https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0/?track=md-dp&batchId=144

#include<bits/stdc++.h>
using namespace std;
#define int long long

int arr[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

vector<int> ans;
//recursive
void minimumnoofcoins(int n){
    if(n==0){
        return;
    }
    for(int i=9;i>=0;i--){
        if(arr[i]<=n){
            int val= n/arr[i];
            for(int j=0;j<val;j++) ans.push_back(arr[i]);

            minimumnoofcoins(n-(val*arr[i]));
            return;
        }
    }
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
        ans.clear();
        minimumnoofcoins(n);
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}