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
Node* add2LL(Node *head1,Node *head2)
{
    if(head1==nullptr) return head2;
    if(head2==nullptr) return head1;
    LinkedList l3;
    Node *p3;
    int carry = 0;
    Node *p1 = head1;
    Node *p2 = head2;
    while((p1!=nullptr || p2!=nullptr) || carry!=0)
    {
        int n1 = (p1!=nullptr) ? p1->data : 0;
        int n2 = (p2!=nullptr) ? p2->data : 0;
        int sum = n1 + n2 + carry;
        if(sum>9)
        {
            carry = sum/10;
            sum = sum%10;
        }
        else if(sum<=9) carry = 0; 
        if(l3.head==nullptr) 
        {
            l3.head = new Node(sum);
            p3 = l3.head;
        }
        else
        {
            p3->next = new Node(sum);
            p3 = p3->next;
        }
        if(p1!=nullptr) p1=p1->next;
        if(p2!=nullptr) p2=p2->next;
    }
    return l3.head;
}
int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(8);
    // head1->next->next = new Node(9);
    // head1->next->next->next = new Node(9);
    // head1->next->next->next->next = new Node(9);
    // head1->next->next->next->next->next = new Node(9);
    // head1->next->next->next->next->next->next = new Node(9);
    // creation of second list
    Node *head2 = new Node(0);  
    // head2->next = new Node(9);
    // head2->next->next = new Node(9);
    // head2->next->next->next = new Node(9);
    LinkedList l3;
    l3.head = add2LL(head1, head2);
    l3.traversal();
}