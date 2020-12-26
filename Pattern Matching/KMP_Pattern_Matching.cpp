#include<bits/stdc++.h>
using namespace std;


void makelps(string& pat, int* lps, int m){
    
    int i=1;
    int j=0;
    lps[0]=0;

    while(i<m){
        if(pat[i]==pat[j]){
            lps[i]= j+1;
            j++;
            i++;
        }
        else{
            if(j>0) j= lps[j-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

bool KmpAlgorithm(string& text, string& pat){

    int n= text.length();
    int m= pat.length();

    int lps[m];
    makelps(pat, lps, m);

    int i=0,j=0;

    while(i<n){
        if(text[i]== pat[j]){
            i++;
            j++;
            if(j==m) return 1;
        }
        else{
            if(j>0) j=lps[j-1];
            else i++;
        }
    }

    return 0;

}

int main(){
    string text="AABAACAADAABAABA";
    string pattern="DAABA";

    cout<<KmpAlgorithm(text, pattern)<<endl;

    return 0;
}