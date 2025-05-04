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
    Node *head;
    public:
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
    void reverse()
    {
        Node *p1,*p2,*p3;
        if(head==nullptr) return;
        p1 = nullptr;
        p2 = head;
        p3 = p2->next;
        if(p3==nullptr) return;
        while(p2!=nullptr){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p3!=nullptr) p3 = p3->next;
        }
        head = p1;
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
    list.addNode(6);
    list.traversal();
    list.reverse();
    list.traversal();
}