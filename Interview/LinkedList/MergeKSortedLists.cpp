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
    while(temp->next!=NULL) temp= temp->next;

    temp->next= new Node(d);
    return;
}

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
}


Node* mergeKSortedLists(vector<Node*>& list){

    Node* newHead=NULL;
    Node* temp= NULL;
    int n= list.size();

    while(true){
        int minindex=-1;
        int minval=INT_MAX;

        for(int i=0;i<n;i++){
            if(list[i]==NULL){
                continue;
            }
            else{
                if(list[i]->data < minval){
                    minval= list[i]->data;
                    minindex=i;
                }
            }
        }
        if(minindex==-1) break;
        if(temp==NULL){
            newHead=new Node(minval);
            temp= newHead;
        } else{
            temp->next= new Node(minval);
            temp= temp->next;
        }
        list[minindex]= list[minindex]->next;
    }
    return newHead;
}

int main(){
    Node* head=NULL;
    insert(head, 1);
    insert(head, 4);
    insert(head, 6);

    Node* head2=NULL;
    insert(head2, 2);
    insert(head2, 3);
    insert(head2, 5);

    vector<Node*> v;
    v.push_back(head);
    v.push_back(head2);

    Node* head3= mergeKSortedLists(v);
    printList(head3);

    return 0;
}