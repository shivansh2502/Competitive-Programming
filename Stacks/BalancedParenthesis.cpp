#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

bool balancedParenthesis(string s){
    stack<char> st;
    bool flag=true;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')' && !st.empty()){
            st.pop();
        }
        else{
            flag=false;
            break;
        }
    }
    if(!st.empty()) return false;
    return flag;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s="()()(())((()))";
    cout<<balancedParenthesis(s)<<endl;
    
    return 0;
}
