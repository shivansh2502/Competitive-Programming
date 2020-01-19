#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void printpre(int* a, int s, int e){
    if(s<=e){
        int mid=(s+e)/2;
        cout<<a[mid]<<" ";
        printpre(a,s,mid-1);
        printpre(a,mid+1,e);
    }
    else{
        return;
    }
}

int main(){
    int n;
    cin>>n;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
        }
        a[i]=sum;
    }

    printpre(a,0,n-1);

    return 0;
}