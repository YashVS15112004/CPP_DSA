#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode() {val=0; next=nullptr;}
    ListNode(int val) {this->val=val; this->next=nullptr;}
};
class LinkedList : ListNode
{
    
    public:
    ListNode *head;
    LinkedList(){head = nullptr;}
    void addNode(int data) //At End
    {
        ListNode *newNode = new ListNode(data);
        ListNode *temp = head;
        if(head==NULL)
        {
            head = newNode;
            return;
        }
        while(temp->next!=NULL) temp=temp->next;
        temp->next = newNode;
    }
    void traversal()
    {
        ListNode *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
ListNode* middle(ListNode* &head){
        ListNode*slow= head;
        ListNode*fast= head->next;
        while(fast!=NULL &&fast->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
ListNode* merge(ListNode* &left, ListNode* &right){
        if(left==NULL) return right;
        if(right==NULL) return left;
        ListNode* temp= new ListNode(-1);
        ListNode* mptr= temp;

        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else{
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        while(left!=NULL){
            mptr->next=left;
            mptr=left;
            left=left->next;
        }
        while(right!=NULL){
            mptr->next=right;
            mptr=right;
            right=right->next;
        }
        return temp->next;
}
ListNode* sortList(ListNode* head) {
if(head==NULL || head->next==NULL) return head;
        //break into two halves
        ListNode* mid= middle(head);
        ListNode* left= head;
        ListNode* right= mid->next;
        mid->next=NULL;
        //Sort 
        left=sortList(left);
        right=sortList(right);
        ListNode* mergeLL= merge(left,right);
        return mergeLL;  
}
int main()
{
    ListNode *head1 = new ListNode(50);
    head1->next = new ListNode(5);
    head1->next->next = new ListNode(15);
    head1->next->next->next = new ListNode(10);
    head1->next->next->next->next = new ListNode(30);
    LinkedList l1;
    l1.head = sortList(head1);
    l1.traversal();
}