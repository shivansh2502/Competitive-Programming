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
    func1(a);
    return 0;
}