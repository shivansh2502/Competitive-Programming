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

void buildTree(node* &root){
    int d;
    cin>>d;
    root=new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* n=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            n->left=new node(c1);
            q.push(n->left);
        }
        if(c2!=-1){
            n->right=new node(c2);
            q.push(n->right);
        }
    }
}

void traverse(node* root,map<int, vector<int>> &um, int j){
    if(root==NULL){
        return;
    }
    else{
        um[j].push_back(root->data);
        int l=j-1;
        int r=j+1;
        traverse(root->left, um, l);
        traverse(root->right,um, r);
    }
}


int main(){
    int n;
    cin>>n;
    node* root=NULL;
    buildTree(root);
    map<int, vector<int>> um;
    traverse(root,um,0);
    for(auto i:um){
        for(int j=0;j<i.second.size();j++){
            cout<<i.second[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}