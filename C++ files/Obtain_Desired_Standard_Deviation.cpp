#include<bits/stdc++.h>
using namespace std;

void series(int n, int d) 
{ 
  
    // if S.D. is 0 then print all 
    // elements as 0. 
    if (d == 0) { 
  
        // print n 0's 
        for (int i = 0; i < n; i++) 
            cout << "0 "; 
  
        cout << endl; 
        return; 
    } 
  
    // if S.D. is even 
    if (n % 2 == 0) { 
  
        // print -SD, +SD, -SD, +SD 
        for (int i = 1; i <= n; i++) { 
            cout << pow(-1, i) * d << " "; 
        } 
        cout << endl; 
    } 
    else // if odd 
    { 
        // convert n to a float integer 
        float m = n; 
        float r = (m / (m - 1)); 
        float g = (float)(d * (float)sqrtf(r)); 
  
        // print one element to be 0 
        cout << "0 "; 
  
        // print (n-1) elements as xi derived 
        // from the formula 
        for (int i = 1; i < n; i++) { 
            cout << pow(-1, i) * g << " "; 
        } 
        cout << endl; 
    } 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,sd;
        cin>>n>>sd;
        if(n==1){
            cout<<"-1"<<endl;
        }
        else{
            series(n,sd);
        }
    }
}