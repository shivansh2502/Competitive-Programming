#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main(){

    int t ,s,q;  
    cin >> t >> s >>q;     
    int count=0;
    int downloaded=s; 

    while(downloaded <t){
        
        downloaded= downloaded *q;
        count++; 
    }
    cout<< count <<endl; 
       
    return 0;
}