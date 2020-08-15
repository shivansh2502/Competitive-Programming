#include<bits/stdc++.h>
using namespace std;

int mat[9][9];

bool isSafe(int i, int j, int k){
    for(int x=0;x<9;x++){
        if(mat[x][j]==k && x!=i){
            return false;
        }
    }

    for(int x=0;x<9;x++){
        if(mat[i][x]==k && x!=j){
            return false;
        }
    }

    if(i<3){
        if(j<3){
            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
        else if(j<6){
            for(int x=0;x<3;x++){
                for(int y=3;y<6;y++){
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
        else if(j<9){
            for(int x=0;x<3;x++){
                for(int y=6;y<9;y++){
                    
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
    }

    else if(i<6){
        if(j<3){
            for(int x=3;x<6;x++){
                for(int y=0;y<3;y++){
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
        else if(j<6){
            for(int x=3;x<6;x++){
                for(int y=3;y<6;y++){
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
        else if(j<9){
            for(int x=3;x<6;x++){
                for(int y=6;y<9;y++){
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
    }

    else if(i<9){
        if(j<3){
            for(int x=6;x<9;x++){
                for(int y=0;y<3;y++){
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
        else if(j<6){
            for(int x=6;x<9;x++){
                for(int y=3;y<6;y++){
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
        else if(j<9){
            for(int x=6;x<9;x++){
                for(int y=6;y<9;y++){
                    if(mat[x][y]==k){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool solveSudoku(int i, int j){

    if(i==9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(mat[i][j]==0){
        for(int k=1;k<=9;k++){
            if(isSafe(i, j, k)){
                mat[i][j]=k;
                bool ans;
                if(j+1<9)
                    ans= solveSudoku(i,j+1);
                else
                    ans= solveSudoku(i+1, 0);

                if(ans==true) return true;
                mat[i][j]=0;
            }
        }
    }
    else{
        bool ans;
        if(j+1<9) ans=solveSudoku(i, j+1);
        else ans=solveSudoku(i+1, 0);
        return ans;
    }
    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>mat[i][j];
            }
        }

        solveSudoku(0, 0);
        cout<<endl;

    }
    return 0;
}