#include<bits/stdc++.h>
using namespace std;
#define MAX 10

int visited[MAX][MAX];
vector<string> printPaths(int m[MAX][MAX], int n, int i, int j){
    
    visited[i][j]=1;
    vector<string> ans;
    if(i==n-1 && j==n-1 && m[i][j]==1){
        ans.push_back("");
        visited[i][j]=-1;
        return ans;
    }
    if(m[i][j]==1){
        if(i+1<n){
            if(m[i+1][j]==1 && visited[i+1][j]!=1){
                vector<string> s= printPaths(m, n, i+1, j);
                for(auto i:s){
                    i+='D';
                    ans.push_back(i);
                }
            }
        }
        if(i-1>=0){
            if(m[i-1][j]==1 && visited[i-1][j]!=1){
                vector<string> s= printPaths(m, n, i-1, j);
                for(auto i:s){
                    i+='U';
                    ans.push_back(i);
                }
            }
        }
        if(j+1<n){
            if(m[i][j+1]==1 && visited[i][j+1]!=1){
                vector<string> s= printPaths(m, n, i, j+1);
                for(auto i:s){
                    i+='R';
                    ans.push_back(i);
                }
            }
        }
        if(j-1>=0){
            if(m[i][j-1]==1 && visited[i][j-1]!=1){
                vector<string> s= printPaths(m, n, i, j-1);
                for(auto i:s){
                    i+='L';
                    ans.push_back(i);
                }
            }
        }
    }
    visited[i][j]=-1;
    return ans;
}

vector<string> printPath(int m[MAX][MAX], int n) {
    
    // Your code goes here
    memset(visited, -1, sizeof(visited));
    vector<string> ans= printPaths(m, n, 0, 0);
    for(auto &i:ans){
        reverse(i.begin(), i.end());
    }
    sort(ans.begin(),ans.end());
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m[MAX][MAX];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }

        vector<string> res= printPath(m, n);
        if(res.size()==0){
            cout<<-1<<endl;
        }
        else{
            for(auto i:res) cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}