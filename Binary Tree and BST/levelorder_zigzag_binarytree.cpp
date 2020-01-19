#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=right=NULL;
    }
};

void buildTree(node* &root){
    int d;
    cin>>d;
    root=new node(d);
    string l;
    cin>>l;
    if(l=="true"){
        buildTree(root->left);
    }
    string r;
    cin>>r;
    if(r=="true"){
        buildTree(root->right);
    }
    return;
}

int height(node* root){
    if(root==NULL){
        return 0;
    }

    int le=height(root->left);
    int ri=height(root->right);
    return max(le,ri) + 1;

}

void printklevelodd(node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
    }
    printklevelodd(root->left,k-1);
    printklevelodd(root->right,k-1);
}

void printkleveleven(node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
    }
    printkleveleven(root->right,k-1);
    printkleveleven(root->left,k-1);
}


int main(){
    node* root=NULL;
    buildTree(root);
    int h=height(root);
    for(int i=1;i<=h;i++){
        if(i%2!=0){
            printklevelodd(root,i);
        }
        else{
            printkleveleven(root,i);
        }
    }
    return 0;
}