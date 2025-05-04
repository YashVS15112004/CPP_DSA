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
};
int intersectionPoint(Node *head1,Node *head2)
{
    if(head1==nullptr) return -1;
    if(head2==nullptr) return -1;
    Node *p1 = head1;
    Node *p2 = head2;
    int l1 = 0,l2 = 0;
    while(p1!=nullptr)
    {
        l1++;
        p1=p1->next;
    }
    while(p2!=nullptr) 
    {
        l2++;
        p2=p2->next;
    }
    p1 = head1;
    p2 = head2;
    int diff = (l2-l1);
    if(diff>0) 
    {
        int cnt = 1;
        while(cnt<=diff) 
        {
            p2 = p2->next;
            cnt++;
        }
    }
    else if(diff<0)
    {
        diff = -(diff);
        int cnt = 1;
        while(cnt<=diff) 
        {
            p1 = p1->next;
            cnt++;
        }
    }
    while(p1!=nullptr && p2!=nullptr)
    {
        if(p1==p2) return p1->data;
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}
int main()
{
    Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(30);
    // creation of second list
      Node *head2 = new Node(3);  
      head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = head1->next;
    cout<<intersectionPoint(head1, head2);
}