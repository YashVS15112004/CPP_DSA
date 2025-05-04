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
    void delete_mid() {
        Node *slow,*fast,*p1;
        if(head==nullptr) return;
        slow = head;
        fast = head;
        p1 = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            p1 = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        p1->next = slow->next;
        delete slow;
    }
};
int main()
{
    LinkedList l;
    l.head = new Node(1);
    l.head->next = new Node(2);
    l.head->next->next = new Node(3);
    l.head->next->next->next = new Node(1);
    l.head->next->next->next->next = new Node(2);
    l.head->next->next->next->next->next = new Node(1);
    l.delete_mid();
    l.traversal();
}