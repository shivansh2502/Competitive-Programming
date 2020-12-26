#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node *left, *right;

    Node(int d){
        data=d;
        left=right=NULL;
    }
};

Node* lca_BT(Node* root ,int n1 ,int n2 ){
   //Your code here 
   if(root==NULL) return NULL;
   
   Node* a= lca_BT(root->left, n1, n2);
   Node* b= lca_BT(root->right, n1, n2);
   
   if(root->data==n1 || root->data==n2) return root;
   
   if(a!=NULL && b!=NULL){
       if((a->data==n1 && b->data==n2) || (a->data==n2 && b->data==n1)) return root;
   }
   
    if(a!=NULL) return a;
    if(b!=NULL) return b;
    return NULL;
}

Node* LCA_BST(Node *root, int n1, int n2){
   //Your code here
   if(root==NULL) return NULL;
   
   if((n1<root->data) && (n2<root->data)) return LCA_BST(root->left, n1, n2);
   if((n1>root->data) && (n2>root->data)) return LCA_BST(root->right, n1, n2);
   
   return root;
}

void BuildTree(Node* &root){
    int d;
    cin>>d;
    if(d==-1) return;
    
    Node* n= new Node(d);
    root=n;
    BuildTree(root->left);
    BuildTree(root->right);
    return;
}

void printTree(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
    return;
}

int main(){

    Node* root=NULL;

    BuildTree(root);
    printTree(root);

    return 0;
}