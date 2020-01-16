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

node* buildtreefrominandpre(int* pre, int* in, int s, int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    node* root=new node(pre[i]);
    int index=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }

    i++;

    root->left = buildtreefrominandpre(pre, in, s, index-1);
    root->right = buildtreefrominandpre(pre, in, index+1, e);
    return root;
}

void printTree(node*root){
	if(root==NULL){
	    return;
	}
    if(root->right!=NULL&&root->left!=NULL){
        cout<<root->left->data<<" => "<<root->data<<" <= "<<root->right->data<<endl;
    }
	if(root->left==NULL&&root->right==NULL){
		cout<<"END => "<< root->data <<" <= END"<<endl;
	}
	if(root->left==NULL&&root->right!=NULL){
		cout<<"END => "<< root->data <<" <= "<<root->right->data<<endl;
	}
	if(root->right==NULL&&root->left!=NULL){
		cout<<root->left->data<<" => "<< root->data <<" <= END"<<endl;
	}
	
	printTree(root->left);
	printTree(root->right);

}


int main(){
    int n;
    cin>>n;
    int pre[100];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    int m;
    cin>>m;
    int in[100];
    for(int i=0;i<m;i++){
        cin>>in[i];
    }
    node* root=buildtreefrominandpre(pre, in, 0, n-1);
    printTree(root);
    return 0;
}