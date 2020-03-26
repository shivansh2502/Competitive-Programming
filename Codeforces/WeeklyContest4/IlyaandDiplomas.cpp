#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int min1, max1, min2, max2, min3, max3;
    cin>>min1>>max1;
    cin>>min2>>max2;
    cin>>min3>>max3;

    int a,b,c;
    a=min1;
    b=min2;
    c=min3;
    while((a+b+c) < n && a<max1){
        a++;
    }

    while((a+b+c) < n && b<max2){
        b++;
    }

    while((a+b+c) < n && c<max3){
        c++;
    }

    cout<<a<<" "<<b<<" "<<c<<endl;

	
	return 0;
}