// Difficult Question
#include<bits/stdc++.h>
using namespace std;

int maxXorSubset(int a[], int n){
    int index=0;

    for(int i=31;i>=0;i--){

        int maxInd= index;
        int maxEle= INT_MIN;
        for(int j=index;j<n;j++){
            if( (a[j] & 1<<i)!=0 && a[j]> maxEle){
                maxEle= a[j];
                maxInd= j;
            }
        }
        if(maxEle==INT_MIN) continue;

        swap(a[index], a[maxInd]);
        maxInd= index;

        for(int j=0;j<n;j++){
            if(j!=maxInd && (a[j] & 1<<i)!=0){
                a[j]= a[j]^ a[maxInd];
            }
        }
        index++;
    }

    int res=0;
    for(int i=0;i<n;i++){
        res^=a[i];
    }
    return res;
}

int main(){
    int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];

        cout<<maxXorSubset(a, n)<<endl;
	    
	}
}