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

void insert(Node* &head, int d){
    if(head==NULL){
        head= new Node(d);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* x= new Node(d);
    temp->next=x;
    return;
}

int KthfromEnd(Node* head, int k){
    Node* ans=head;
    Node* ref=head;
    if(head!=NULL){
        int count=0;
        while(count<k){
            if(ref==NULL) return -1;
            ref=ref->next;
            count++;
        }
    }
    while(ref!=NULL){
        ans= ans->next;
        ref= ref->next;
    }
    return ans->data;
}

void print(Node* root){
    
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->next;
    }
    return;
}

int main(){
    Node* head=NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    // print(head);
    // cout<<"\n";
    cout<<KthfromEnd(head, 3)<<endl;
    return 0;
}