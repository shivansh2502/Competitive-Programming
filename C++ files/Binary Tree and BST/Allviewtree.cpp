#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    int hd;
    node(int d){
        data=d;
        left=right=NULL;
    }
};


void buildfromlevelorder(node* &root){
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

void printBottomview(node* root){
    if(root==NULL){
        return;
    }

    queue<node*> q;
    map<int, int> m;
    int hd=0;
    root->hd=hd;
    q.push(root);

    while(!q.empty()){
        
        hd=root->hd;
        
        
        m[hd]=root->data;
        
        if(root->left){
            root->left->hd=hd-1;
            q.push(root->left);
        }
        if(root->right){
            root->right->hd=hd+1;
            q.push(root->right);
        }
        
        q.pop();
        root=q.front();
    }

    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
    }

}

void printTopview(node* root){
    if(root==NULL){
        return;
    }

    queue<node*> q;
    map<int, int> m;
    int hd=0;
    root->hd=hd;
    q.push(root);

    while(!q.empty()){
        
        hd=root->hd;
        
        if(m.count(hd)==0){
            m[hd]=root->data;
        }
        if(root->left){
            root->left->hd=hd-1;
            q.push(root->left);
        }
        if(root->right){
            root->right->hd=hd+1;
            q.push(root->right);
        }
        
        q.pop();
        root=q.front();
    }

    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
    }

}

void printLeftview(node* root, int level, int &max_level){
    if(root==NULL){
        return;
    }
    if(max_level<level){
        cout<<root->data<<" ";
        max_level=level;
    }
    printLeftview(root->left, level+1, max_level);
    printLeftview(root->right, level+1, max_level);

}

void printRightview(node* root, int level, int &max_level){
    if(root==NULL){
        return;
    }
    if(max_level<level){
        cout<<root->data<<" ";
        max_level=level;
    }
    printRightview(root->right, level+1, max_level);
    printRightview(root->left, level+1, max_level);
    
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

int main(){
    node* root=NULL;
    buildfromlevelorder(root);
    int max_level=0;
    printBottomview(root);
    
    return 0;
}


//law of big three
//law of big 5