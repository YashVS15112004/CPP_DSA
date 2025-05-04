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
    bool isPalindrome(Node *head) {
        Node *slow,*fast;
        if(head==nullptr) return false;
        slow = head;
        fast = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *p1,*p2,*p3,*tail,*h2;
        p1 = nullptr;
        p2 = slow;
        p3 = slow->next;
        tail = slow;
        while(p2!=nullptr)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p3!=nullptr)p3 = p3->next;
        }
        h2 = p1;
        p1 = head;
        p2 = h2;
        while(p1!=slow && p2!=nullptr)
        {
            if(p1->data!=p2->data) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true; 
    }
};
int main()
{
    LinkedList l;
    l.head = new Node(1);
    l.head->next = new Node(2);
    l.head->next->next = new Node(3);
    l.head->next->next->next = new Node(2);
    l.head->next->next->next->next = new Node(1);
    cout<<l.isPalindrome(l.head);
}