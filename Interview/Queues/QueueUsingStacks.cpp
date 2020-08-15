#include<bits/stdc++.h>
using namespace std;

class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop(); // using 2 stacks
    int pop2(); // using single stack
};

void StackQueue :: push(int x){
    s1.push(x);
}

// using 2 stacks
int StackQueue :: pop(){
    if(s1.empty()) return -1;
    while(!s1.empty()){
        int a=s1.top();
        s1.pop();
        s2.push(a);
    }
    int ans= s2.top();
    s2.pop();
    while(!s2.empty()){
        int a= s2.top();
        s2.pop();
        s1.push(a);
    }
    return ans;
}

// using 1 stack + function call stack 
int StackQueue :: pop2(){
    if(s1.empty()) return -1;
    
    int x= s1.top();
    s1.pop();
    if(s1.empty()) return x;

    int ans= pop2();
    s1.push(x);
    return ans;
}

int main(){
    
    return 0;
}