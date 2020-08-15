#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
    int pop2();
};

void QueueStack :: push(int x){
    q1.push(x);
}

int QueueStack :: pop(){
    if(q1.empty()) return -1;
    while(q1.size()!=1){
        int a= q1.front();
        q1.pop();
        q2.push(a);
    }
    int ans= q1.front();
    q1.pop();
    while(!q2.empty()){
        int a=q2.front();
        q2.pop();
        q1.push(a);
    }
    return ans;
}




int main(){

}
