#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertatHead(ListNode*&head, int data){
    ListNode* new_node=new ListNode(data);
    new_node->next= head;
    head=new_node; 
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int num1=0;
    int pow=1;
    while(l1->next!=NULL){
        num1+=pow*l1->val;
        pow*=10;
        cout<<num1<<endl;
    }

    int num2=0;
    pow=1;
    while(l2->next!=NULL){
        num2+=pow* l2->val;
        pow*=10;
    }
    int ans=num1+num2;
    cout<<ans<<endl;
    ListNode* head=NULL;
    while(ans>0){
        int p=ans%10;
        ans=ans/10;
        insertatHead(head, p);
    }
    return head;    
}

int main() {
    ListNode* l1=NULL;
    insertatHead(l1, 1);
    insertatHead(l1, 1);
    insertatHead(l1, 1);
    int num1=0;
    int pow=1;
    while(l1->next!=NULL){
        num1+=pow*l1->val;
        pow*=10;
        cout<<num1<<endl;
    }

    ListNode* l2=NULL;
    insertatHead(l2, 1);
    insertatHead(l2, 1);
    insertatHead(l2, 1);

    ListNode* ans=addTwoNumbers(l1, l2);
    while(ans!=NULL){
        cout<<ans->val;
        ans=ans->next;
    }
    return 0;

}
