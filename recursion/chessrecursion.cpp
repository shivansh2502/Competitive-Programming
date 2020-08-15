/*You are given a 10X10 chessboard with a knight on coordinate (I). You have to find the number of blocks on the chessboard that the knight can be at in exactly N moves.

NOTE:

The knight can move from its positon in the diagram to all the coordinates marked by X in the following diagram in one move. For the 10x10 chessboard (1,1) is the top-left corner.(1, 10) is the top-right corner and (10.10) is

the bottom-right corner.

INPUT

Input will consist of three space seperated integers IN

Nis less than 10.

OUTPUT

Print a single integer denoting the number of blocks on the chessboard that the knight can be at in exactly N moves.

Problem Setter - Sheldon

SAMPLE INPUT

SAMPLE OUTPUT

331

8

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

void func(int i, int j, int n, unordered_map<pair<int, int>, bool,  hash_pair> &um){
    if(i<1 || i>10 || j<1 || j>10){
        return;
    }
    if(n==0){
        if(!um.count(make_pair(i, j))){
            um[make_pair(i, j)]= true;
        }
    }
    else{
        func(i+2,j+1, n-1, um);
        func(i+1,j+2, n-1, um);
        func(i+2,j-1, n-1, um);
        func(i+1,j-2, n-1, um);
        func(i-2,j+1, n-1, um);
        func(i-1,j+2, n-1, um);
        func(i-2,j-1, n-1, um);
        func(i-1,j-2, n-1, um);
    }
    return;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i, j, n;
    cin>>i>>j>>n;

    unordered_map<pair<int, int>, bool,  hash_pair> um;

    func(i, j, n, um);
    int count=0;
    for(auto i:um){
        count++;
    }
    cout<<count<<endl;
    return 0;
}
