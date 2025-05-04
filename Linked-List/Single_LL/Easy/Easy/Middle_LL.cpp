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
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
       
        temp->next = newNode;
    }
    int middle()
    {
        Node *slow = head;
        Node *fast = head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            // if(fast!=nullptr && fast->next!=nullptr && fast->next->next==nullptr) return slow->next->data; 
            // Above Line Will Also Work But Without This Line The Code Will Work!
        }
        return slow->data;
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
    cout<<list.middle();
}