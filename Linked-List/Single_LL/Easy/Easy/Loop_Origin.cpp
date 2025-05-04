#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node() {data=0; next=nullptr;}
    Node(int val) {this->data=val; this->next=nullptr;}
};
class LinkedList : Node
{
    
    public:
    Node *head;
    LinkedList(){head = nullptr;}
    void addNode(int data) //At End
    {
        Node *newNode = new Node(data);
        Node *temp = head;
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
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    int cycleOrigin(Node *head) {
        Node *slow,*fast;
        slow = head;
        fast = head;
       while(fast!=nullptr && fast->next!=nullptr)
       {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                slow = head;
                while(slow!=fast)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow->data;
            }
       }
       return -1; 
    }
};
int main()
{
    LinkedList l;
    l.head = new Node(10);
    l.head->next = new Node(20);
    l.head->next->next = new Node(30);
    l.head->next->next->next = new Node(40);
    l.head->next->next->next->next = new Node(50);
    //l.head->next->next->next->next->next = new Node(60);
    // Creating a loop resulting in the linked list:
    // 10 -> 20 -> 30 -> 40 -> 10 -> 20 -> 30 ...
    l.head->next->next->next->next->next = l.head->next;
    cout<<l.cycleOrigin(l.head);

}