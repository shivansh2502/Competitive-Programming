#include<bits/stdc++.h>
using namespace std;


vector<int> bina(string str){ 

    vector<int> re(32); 
    int a, b, c, d, i, rem; 
    a = b = c = d = 1; 
    stack<int> st; 
    int ar[4];

    int l=0;
    int curvalue=0;
    for(unsigned int i=0;i<str.length();i++){
        if(str[i]=='.'){
            ar[l]=curvalue;
            l++;
            curvalue=0;
        }
        else{
            curvalue= curvalue*10 + (str[i]-'0');
        }
    } 
    ar[l]= curvalue;
    
    a = ar[0]; 
    b = ar[1]; 
    c = ar[2]; 
    d = ar[3]; 

        
    // convert first number to binary 
    for (i = 0; i <= 7; i++){ 
        rem = a % 2; 
        st.push(rem); 
        a = a / 2; 
    } 
        
    // Obtain First octet 
    for (i = 0; i <= 7; i++) { 
        re[i] = st.top();
        st.pop(); 
    } 
        
    // convert second number to binary 
    for (i = 8; i <= 15; i++) { 
        rem = b % 2; 
        st.push(rem); 
        b = b / 2; 
    } 
        
    // Obtain Second octet 
    for (i = 8; i <= 15; i++) { 
        re[i] = st.top(); 
        st.pop();
    } 
        
    // convert Third number to binary 
    for (i = 16; i <= 23; i++) { 
        rem = c % 2; 
        st.push(rem); 
        c = c / 2; 
    } 
        
    // Obtain Third octet 
    for (i = 16; i <= 23; i++) { 
        re[i] = st.top();
        st.pop(); 
    } 
        
    // convert fourth number to binary 
    for (i = 24; i <= 31; i++) { 
        rem = d % 2; 
        st.push(rem); 
        d = d / 2; 
    } 
        
    // Obtain Fourth octet 
    for (i = 24; i <= 31; i++) { 
        re[i] = st.top();
        st.pop(); 
    } 
        
    return re; 
} 


vector<int> decil(int bi[]){   

    vector<int> arr(4); 
    int a, b, c, d, i, j; 
    a = b = c = d = 0; 
    j = 7; 
        
    for (i = 0; i < 8; i++) { 
        a = a + (int)(pow(2, j)) * bi[i]; 
        j--; 
    } 
        
    j = 7; 
    for (i = 8; i < 16; i++) { 
        b = b + bi[i] * (int)(pow(2, j)); 
        j--; 
    } 
        
    j = 7; 
    for (i = 16; i < 24; i++) {    
        c = c + bi[i] * (int)(pow(2, j)); 
        j--; 
    } 
        
    j = 7; 
    for (i = 24; i < 32; i++) {    
        d = d + bi[i] * (int)(pow(2, j)); 
        j--; 
    } 
        
    arr[0] = a; 
    arr[1] = b; 
    arr[2] = c; 
    arr[3] = d; 
    return arr; 
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	int n, r;
    cin>>n>>r;
    string s[n];
    string e[n];
    string name[n];
    for(int i=0;i<n;i++) cin>>s[i]>>e[i]>>name[i];

    int start[n][4];
    int end[n][4];

    

    for(int i=0;i<n;i++){
        // cout<<s[i]<<" "<<e[i]<<endl;
        int indexx=0;
        int indexy=0;
        bool flag=false;
        int nx=0;
        for(unsigned int j=0;j<s[i].length();j++){
            if(s[i][j]=='/'){
                indexx=j;
                flag=true;
                continue;
            }
            if(flag==true) nx= nx*10 + (s[i][j]-'0');
        }

        flag=false;
        int ny=0;

        for(unsigned int j=0;j<e[i].length();j++){
            if(e[i][j]=='/'){
                indexy=j;
                flag=true;
                continue;
            }
            if(flag==true) ny= ny*10 + (e[i][j]-'0');
        }
        
        vector<int> x= bina(s[i].substr(0, indexx-1));
        vector<int> y= bina(e[i].substr(0, indexy-1));

        int ntwk[32]={0}; 
        int brd[32]={0}; 
        int tx = 32 - nx; 
        int ty=  32 - ny;
        for (int i = 0; i <= (31 - tx); i++) ntwk[i] = x[i]; 
        for (int i = 0; i <= (31 - ty); i++) brd[i] = y[i]; 
        for (int i = 31; i > (31 - tx); i--) ntwk[i] = 0; 
        for (int i = 31; i > (31 - ty); i--) brd[i] = 1; 

        vector<int> ax= decil(ntwk);
        vector<int> ay= decil(brd);

        for(int j=0;j<4;j++) {
            start[i][j]=ax[j];
            end[i][j]= ay[j];
        }
      
    }

    string ranks[r];
    for(int i=0;i<r;i++){
        cin>>ranks[i];
        int a[4];
        int k=0;
        int curvalue=0;
        for(unsigned int j=0;j<ranks[i].length();j++){
            if(ranks[i][j]=='.'){
                a[k++]=curvalue;
                curvalue=0;
            }
            else curvalue =  curvalue*10 + (ranks[i][j]-'0'); 
        }
        a[k]=curvalue;

        bool f=false;
        for(int j=0;j<n;j++){
            bool flag=false;
            bool x=false;
            bool y=false;
            for(int k=0;k<4;k++){
                if(y==true){
                    if(start[j][k]< a[k]){
                        flag=true;
                        break;
                    }
                    else if(start[j][k]==a[k]){
                        if(k==3) flag=true;
                        else continue;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                else if(x==true){
                    if(end[j][k]> a[k]){
                        flag=true;
                        break;
                    }
                    else if(end[j][k]==a[k]){
                        if(k==3) flag=true;
                        else continue;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                else{
                    if(start[j][k]<a[k] && end[j][k]>a[k]){
                        x=true;
                        y=true;
                        flag=true;
                        break;
                    }
                    if(start[j][k]<=a[k] && end[j][k]>=a[k]){
                        if(a[k]==end[j][k]) x=true;
                        else if(a[k]==start[j][k]) y=true;
                        continue;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
            if(flag){
                cout<<name[j]<<endl;
                f=true;
                break;
            }
        }
        if(!f){
            cout<<"None"<<endl;
        }
    }
 

	return 0;
}