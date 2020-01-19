#include<bits/stdc++.h>
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

node* insertinBST(node* root, int data){
    if(root==NULL){
        return new node(data);
    }
    if(data<=root->data){
        root->left=insertinBST(root->left,data);
    }
    else{
        root->right=insertinBST(root->right,data);
    }
    return root;
}

void printTree(node* root){
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<" "; 
        printTree(root->left);
        printTree(root->right);
    }
}

node* deletenode(node* root, int k){
    if(root==NULL){
        return NULL;
    }
    if(k<root->data){
        root->left=deletenode(root->left,k);
        return root;
    }
    else if(k==root->data){
        //node found
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        else if(root->right!=NULL && root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else{
            node* replace=root->left;
            while(replace->right!=NULL){
                replace=replace->right;
            }
            root->data=replace->data;
            root->left=deletenode(root->left,replace->data);
            return root;
        }
    }
    else{
        root->right=deletenode(root->right,k);
        return root;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[10000];
        node* root=NULL;
        for(int i=0;i<n;i++){
            cin>>a[i];
            root=insertinBST(root,a[i]);
        }

        // buildTree(root,a,n);
        // printTree(root);
        int k;
        cin>>k;
        int del[100000];
        for(int i=0;i<k;i++){
            cin>>del[i];
            root=deletenode(root,del[i]);
        }
        printTree(root);

    }
    return 0;
}