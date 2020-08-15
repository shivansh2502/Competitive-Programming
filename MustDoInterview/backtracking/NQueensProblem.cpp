#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
    
    //column is safe check
    for(int row=0;row<i;row++)
        if(board[row][j]==1) return false;

    
    //left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1) return false;
        x--;
        y--;
    }
    
    //right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1) return false;
        x--;
        y++;
    }

    return true;
}

bool solveNQueen(int board[][10], int i, int n){
    //base case
    if(i==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1) cout<<"Q ";
                else cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return false;
    }
    
    //recursive case
    for(int j=0;j<n;j++){
        if(isSafe(board, i, j, n)){
            board[i][j]=1;
            bool everythingworks = solveNQueen(board, i+1, n);
            if(everythingworks) return true;
            board[i][j]=0;
        }    
    }
    return false;
    
}

int main()
{
    int n;
    cin>>n;
    
    int board[10][10]={0};
    solveNQueen(board,0, n);
    return 0;
}
