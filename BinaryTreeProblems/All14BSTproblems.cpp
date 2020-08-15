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

void insert( node*& root, int d){
    if(root==NULL){
        node* n= new node(d);
        root=n;
        return;
    }
    else{
        if(d<=root->data){
            insert(root->left, d);
        }
        else{
            insert(root->right, d);
        }
    }
}

int size(node *root){
    if(root==NULL){
        return 0;
    }   
    else{
        int leftsize = size(root->left);
        int rightsize = size(root->right);
        return leftsize+rightsize+1;
    }
}

int maxdepth(node *root){
    if(root==NULL){
        return 0;
    }
    else{
        int left= maxdepth(root->left);
        int right= maxdepth(root->right);
        return max(left+1, right+1);
    }
}

int minValue(node *root){

    if(root->left==NULL){
        return root->data;
    }
    else{
        return minValue(root->left);
    }
}

int maxValue(node *root){
    if(root->right==NULL){
        return root->data;
    }
    else{
        return maxValue(root->right);
    }
}

void printpreorder(node *root){
    if(root==NULL){
        return;
    }
    else{
        cout<<root->data<<" ";
        printpreorder(root->left);
        printpreorder(root->right);
    }
}

void printinorder(node *root){
    if(root==NULL){
        return;
    }
    else{
        printinorder(root->left);
        cout<<root->data<<" ";
        printinorder(root->right);
    }
}

void printpostorder(node *root){
    if(root==NULL){
        return;
    }
    else{
        printpostorder(root->left);
        printpostorder(root->right);
        cout<<root->data<<" ";
    }
}

bool hasSumPath(node *root, int sum){

    if(root==NULL){
        return (sum==0);
    }
    
    else{
        int subSum= sum- root->data;
        return (hasSumPath(root->left, subSum) || hasSumPath(root->right, subSum));
    }
}

vector<int> v;
void printPaths(node *root){

    v.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else{
        if(root->left!=NULL){
             printPaths(root->left);
            v.pop_back();
        }
        if(root->right!=NULL){
            printPaths(root->right);
            v.pop_back();
        }
    }
}

void mirrorImage(node *&root){
    if(root==NULL){
        return;
    }
    else{
        swap(root->left, root->right);
        mirrorImage(root->left);
        mirrorImage(root->right);
    }
}


void doubleTree(node *&root){
    if(root==NULL){
        return;
    }
    else{
        node *n= new node(root->data);
        n->left= root->left;
        root->left=n;
        doubleTree(root->left->left);
        doubleTree(root->right);
    }
}

bool sameTree(node *root1, node *root2){
    if(root1==NULL && root2==NULL){
        return true; 
    }
    else if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
        return false;
    }
    else{
        if(root1->data == root2->data){
            if(sameTree(root1->left, root2->left) && sameTree(root1->left, root2->left)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
}

//this is equal to catlan number i.e. (2n)!/((n)!*(n+1)!)
int countTrees(int n){
    if(n<=1){
        return 1;
    }
    else{
        int sum=0;
        
        for(int root=1; root <= n; root++){
            int left= countTrees(root-1);
            int right= countTrees(n- root);
            sum+= left*right; 
        }
        return sum;
    }
}

bool isBst1(node* root){
    if(root==NULL){
        return true; 
    }
    else{
        int maxl, minr;
        if(root->left!=NULL ){
            maxl= maxValue(root->left);
        }
        else maxl= 0;
        if(root->right!=NULL){
            minr= minValue(root->right);
        }
        else minr= root->data + 1;
    
        if(maxl<=root->data &&
            minr> root->data &&
            isBst1(root->left) &&
            isBst1(root->right)
        ){
            return true;
        }  
        else{
            return false;
        }
    }
}

bool isBstUtil( node * root, int min, int max){
    if(root== NULL) return true;

    if((root->data > min && root->data <= max)  && isBstUtil(root->left, min, root->data) && isBstUtil(root->right,root->data, max)) 
        return true;
        
    return false;
}

bool isBst2(node * root){
    return isBstUtil(root, INT_MIN, INT_MAX);
}


int main(){
    
    node *root= NULL;
    insert(root, 3);
    insert(root, 2);
    insert(root, 1);
    insert(root, 6);
    insert(root, 9);
    insert(root, 5);
    insert(root, 10);

    node *root2= NULL;
    insert(root2, 3);
    insert(root2, 2);
    insert(root2, 1);
    insert(root2, 6);
    insert(root2, 9);
    insert(root2, 5);
    insert(root2, 10);

    cout<<"Size of the tree is : "<<size(root)<<endl;
    cout<<"Maximum Depth or height of the tree is : "<<maxdepth(root)<<endl;
    cout<<"Minimum Value in the tree is : "<<minValue(root)<<endl;

    cout<<"PreOrder : ";
    printpreorder(root);
    cout<<endl;

    cout<<"InOrder : ";
    printinorder(root);
    cout<<endl;
    
    cout<<"PostOrder : ";
    printpostorder(root);
    cout<<endl;

    cout<<"Has sum path : "<<hasSumPath(root, 7);

    cout<<endl;
    cout<<"Print all the paths from root to leaf:"<<endl;
    printPaths(root);

    mirrorImage(root);
    mirrorImage(root);
    cout<<"InOrder : ";
    printinorder(root);
    cout<<endl;

    doubleTree(root);
    cout<<"InOrder : ";
    printinorder(root);
    cout<<endl;

    cout<<"Same Trees: "<<sameTree(root, root2)<<endl;
    cout<<"COUNT TREES :"<<countTrees(4)<<endl;
    cout<<"Is Bst1: "<<isBst1(root)<<endl;
    cout<<"Is Bst2: "<<isBst2(root)<<endl;

    return 0;
}