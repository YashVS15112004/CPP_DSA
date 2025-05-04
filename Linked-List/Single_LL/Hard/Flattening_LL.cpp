#include <bits/stdc++.h> 
using namespace std; 
class Node
{
    public:
    int data;
    Node *next;
    Node *bottom;

    Node() : data(0), next(nullptr), bottom(nullptr) {};
    Node(int x) : data(x), next(nullptr), bottom(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), bottom(childNode) {}
};
class LinkedList : public Node
{
    
    public:
    Node *head;
    LinkedList(){head = nullptr;}
    LinkedList(Node *h){head = h;}
    void Node_next(int data) //At End
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
    void Node_bottom(int data) //At End
    {
        Node *newNode = new Node(data);
        Node *temp = head;
        if(head==nullptr)
        {
            head = newNode;
            return;
        }
        while(temp->bottom!=nullptr)
        {
            temp=temp->next;
        }
        temp->bottom = newNode;
    }
};
void traversal(Node *h)
{
        Node *temp = h;
        while(temp!=nullptr)
        {
            cout<<temp->data<<"->";
            temp=temp->bottom;
        }
        cout<<"NULL"<<endl;
}
Node* flatten(Node *h)
{
    Node*p1,*p2;
        if(h==nullptr) return h;
        p1 = h->next;
        while(p1!=nullptr)
        {
            Node *p2 = p1->bottom;
            Node *p4 = p1->next;
            while(p1!=nullptr)
            {
                Node *p3 = h;
                if(p3->data >= p1->data)
                {
                    p1->bottom = p3;
                    h = p1;
                }
                else
                {
                    while(p3->bottom!=nullptr && p3->bottom->data<=p1->data) p3 = p3->bottom;
                    p1->bottom = p3->bottom;
                    p3->bottom = p1;
                }
                p1 = p2;
                if(p2!=nullptr) p2 = p2->bottom;
            }
            p1 = p4;
        }
        return h;
}
int main()
{
    Node *h = new Node(5);
    h->bottom = new Node(7);
    h->bottom->bottom = new Node(8);
    h->bottom->bottom->bottom = new Node(30);
    h->next = new Node(10);
    h->next->bottom = new Node(20);
    h->next->next = new Node(19);
    h->next->next->bottom = new Node(22);
    h->next->next->bottom->bottom = new Node(50);
    h->next->next->bottom = new Node(28);
    h->next->next->bottom->bottom = new Node(28);
    h->next->next->bottom->bottom->bottom = new Node(28);
    h->next->next->bottom->bottom->bottom->bottom = new Node(28);
    h = flatten(h);
    traversal(h);
}