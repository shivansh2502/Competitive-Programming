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


bool CycleDetection(Node*& head){
    Node* fast= head;
    Node* slow= head;

    while(fast!=NULL && fast->next!=NULL){
        fast= fast->next->next;
        slow= slow->next;
        if(fast->data==slow->data){
            slow=head;
            if(slow==fast){
                while(fast->next!=slow) fast= fast->next;
            } else{
                while(slow->next != fast->next){
                    slow= slow->next;
                    fast= fast->next;
                }
            }
            fast->next= NULL;
            return 1;
        }
    }
    return 0;
}


int main(){

    Node* head= NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    Node* temp=head->next->next->next;
    temp->next= head->next;

    cout<<CycleDetection(head)<<endl;

    printList(head);


    return 0;
}


/*

2* (l+ n*x + y) =  l + m*x + y

l =  (m-2*n)*x - y;

*/