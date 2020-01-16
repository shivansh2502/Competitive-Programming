#include <bits/stdc++.h>
using namespace std;

void shuffle(int *a, int s, int e){
    int j;
    srand(time(NULL));
    for(int i=e;i>0;i--){
        j=rand()%(i+1);
        swap(a[i],a[j]);
    }
}

int partition(int *a,int s,int e){
    int p=a[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(a[j]<=p){
            i++;
            swap(a[i],a[j]);
        }
    }
    
    swap(a[i+1],a[e]);
    return i+1;
}

void quickSort(int *a, int s, int e){
    if(s>=e){
        return;
    }
    
    int p=partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int main()
{
    int n;
    cin>>n;
    int a[n]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    shuffle(a,0,n-1);
    quickSort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
