#include <bits/stdc++.h> 
using namespace std; 
class Node
{
    public:
    int data;
    Node *next;

    Node() {data=0; next=NULL;}
    Node(int val) {this->data=val; this->next=NULL;}
};
class LinkedList : public Node
{
    
    public:
    Node *head;
    LinkedList(){head = nullptr;}
    void addNode(int data) //At End
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        if(head==nullptr)
        {
            head = newNode;
            return;
        }
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
       
        temp->next = newNode;
    }
    void traversal()
    {
        Node *temp = head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    Node* rotateRight(Node* head,int k) {
        if(head==nullptr) return nullptr;
        int n = 0;
        Node *p1,*p2,*p3,*p4;
        p1 = head;
        while(p1!=nullptr)
        {
            n++;
            p1=p1->next;
        }
        k = k%n;
        if(k==0) return head;
        p1 = head;
        p2 = p1;
        int j = n-k;
        for(int i=1;i<j;i++) p2 = p2->next;
        p3 = p2->next;
        p4 = p3;
        while(p4->next!=nullptr) p4 = p4->next;
        p4->next = p1;
        p2->next = nullptr;
        head = p3;
        return head;
    }
};
int main()
{
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.traversal();
    list.head = list.rotateRight(list.head,2);
    list.traversal();
}