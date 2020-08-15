#include<bits/stdc++.h>
using namespace std;


int join_ropes(int a[], int n){

    priority_queue<int, vector<int>, greater<int>> pq(a, a+n);
    int cost=0;
    while(pq.size()>1){
        int x= pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        cost+= (x+y);
        pq.push(x+y);
    }
    return cost;

}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<join_ropes(a, n)<<endl;
    return 0;
}