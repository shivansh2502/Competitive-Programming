#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void buildTree(node* &root, int d){
    if(root==NULL){
        root=new node(d);
        return;
    }
    else{
        if(d>root->data){
            buildTree(root->right,d);
        }
        else if(d<root->data){
            buildTree(root->left,d);
        }
    }
}


int main(){
    node* root=NULL;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int d;
            cin>>d;
            buildTree(root,d);
        }
    }
    return 0;
}