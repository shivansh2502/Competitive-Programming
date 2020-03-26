#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long


//using 2 extra stacks
void transfer(stack<int> &s1, stack<int> &s2){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
}
void reverseStack(stack<int> &s){
    stack<int> s1;
    stack<int> s2;
    transfer(s, s1);
    transfer(s1, s2);
    transfer(s2, s);
}


//using 1 extra stack
void reverseStack2(stack<int> &s){
    stack<int> s1;
    int n=s.size();
    for(int i=1;i<=n;i++){
        int x=s.top();
        s.pop();
        int k=n-i;
        while(k--){
            s1.push(s.top());
            s.pop();
        }
        s.push(x);
        transfer(s1, s);
    }
}


//using recursion
void insertAtBottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int k=s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(k);
}

void reverseStack3(stack<int> &s){
    if(s.empty()) return;

    int x= s.top();
    s.pop();
    reverseStack3(s);
    insertAtBottom(s, x);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(6);
    s.push(9);

    reverseStack3(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}
