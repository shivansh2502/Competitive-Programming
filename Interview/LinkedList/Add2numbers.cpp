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

void insert(Node*&head, int d){
    if(head==NULL){
        head= new Node(d);
        return;
    }
    Node* temp= head;
    while(temp->next!=NULL) temp= temp->next;

    temp->next= new Node(d);
    return;
}

void printList(Node* head){
    while(head!=NULL) {
        cout<<head->data<<" ";
        head= head->next;
    }
    return;
}

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* head=NULL;
    Node* temp=head;
    int sum=0;
    while(l1!=NULL || l2!=NULL || sum>0){
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        Node* new_node= new Node(sum%10);
        if(head==NULL){
            head= new_node;
            temp=head;
        }
        else{
            temp->next= new_node;
            temp= temp->next;
        }
        sum/=10;
    }
    return head;
}


int main(){

    Node* l1= NULL;
    Node* l2= NULL;
    insert(l1, 1);
    insert(l1, 2);
    insert(l2, 3);
    insert(l2, 4);

    Node* head= addTwoNumbers(l1, l2);
   
    printList(head);


    return 0;
}