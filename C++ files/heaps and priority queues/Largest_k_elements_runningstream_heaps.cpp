#include<bits/stdc++.h>
using namespace std;

void print_queue(priority_queue<int, vector<int>, greater<int>> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){
    int n;
    int k=3;
    int cs=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(scanf("%d",&n)!=EOF){
        if(n==-1){
            print_queue(pq);
        }
        else if(cs<k){
            pq.push(n);
            cs++;
        }
        else{
            if(n>pq.top()){
                pq.pop();
                pq.push(n);
            }
        }
    }

    return 0;
}