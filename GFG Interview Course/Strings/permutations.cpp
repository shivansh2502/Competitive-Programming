#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

vector<string> v;

void permute(char* a, int i){
    if(a[i]=='\0'){
        string s=a;
        v.push_back(s);
        return;
    }

    for(int j=i;a[j]!='\0';j++){
        swap(a[i], a[j]);
        permute(a, i+1);
        swap(a[i], a[j]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        v.clear();
        char a[1000];
        cin>>a;
        int n= strlen(a);
        sort(a,a+n);
        do {
            cout<<a<<" ";
        }while(next_permutation(a, a+n));
    
        // permute(a, 0);
        // sort(v.begin(), v.end());
        // for(auto i :v){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
    }
    return 0;
}
