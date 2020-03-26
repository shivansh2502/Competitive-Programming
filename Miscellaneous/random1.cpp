#include<bits/stdc++.h>
using namespace std;

void func1(int *a){
    for(int i=0;i<10;i++){
        a[i]=i;
        cout<<a[i]<<" ";
    }
}

int main(){
    int a[10];
    // func1(a);
    set<int> s;
    s.insert(7);
    s.insert(10);
    s.insert(1);
    s.insert(0);
    s.insert(101);

    for(auto i:s){
        cout<<i<<endl
    }

    return 0;
}
