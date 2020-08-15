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
    Node* temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* n= new Node(d);
    temp->next=n;
    return;
}

int middleElement(Node* head){
    if(head==NULL) return -1;
    Node* fast= head;
    Node* slow= head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}

int main(){
    Node* head= NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    cout<<middleElement(head)<<endl;

    return 0;
}