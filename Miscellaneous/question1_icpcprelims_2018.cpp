#include<bits/stdc++.h>
using namespace std;
#define ll long long

void buildLowestNumberRec(string str, int n, string &res) 
{ 
    if (n == 0){ 
        res.append(str); 
        return; 
    } 
    int len = str.length(); 
    if (len <= n) 
        return; 
    int minIndex = 0; 
    for (int i = 1; i<=n ; i++) 
        if (str[i] < str[minIndex]) 
            minIndex = i; 
  
    res.push_back(str[minIndex]); 
    string new_str = str.substr(minIndex+1, len-minIndex); 
    buildLowestNumberRec(new_str, n-minIndex, res); 
} 

string buildLowestNumber(string str, int n) 
{ 
    string res = ""; 
    string ans = "";
    // Note that result is passed by reference 
    buildLowestNumberRec(str, n, res);
   // cout<<res<<endl;
    for(ll i=0;i<res.length();i++){
        if(res[i]!='0'){
            for(int j=i;j<res.length();j++){
                ans+=res[j];
            }
            break;
        }
    }
    if(ans.length()==0){
        ans='0';
    } 
    return ans; 
} 
  
// Driver program to test above function 
int main() 
{ 
    ll t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int n = 1; 
        cout << buildLowestNumber(str, n)<<endl; 
    }
    return 0; 
}