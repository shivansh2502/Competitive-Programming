#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        data=d;
        next=NULL;
    }
};

void insert(Node* &root, int d){
    if(root==NULL){
        root=new Node(d);
        return;
    }
    Node* temp=root;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* x= new Node(d);
    temp->next= x;
    return ;
}

void print(Node* root){
    
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
    return;
}


// Linear Approach
void reverseLL(Node* &root){
    Node* temp1=root;
    Node* temp2=NULL;
    Node* temp3=NULL;
    while(temp1!=NULL){
        temp3=temp2;
        temp2=temp1;
        temp1=temp1->next;
        temp2->next=temp3;
    }
    root=temp2;
    return;
}

// Recursive Approach
Node* reverseRec(Node* root, Node* &head){
    if(root==NULL) return NULL;
    if(root->next==NULL){
        head=root;
        return root;
    }
    Node* temp1= reverseRec(root->next, head);
    temp1->next=root;
    root->next=NULL;
    return root;
}

int main(){

    Node* root=NULL;
    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    reverseLL(root);
    print(root);
    Node* head=NULL;
    reverseRec(root, head);
    print(head);

    return 0;
}