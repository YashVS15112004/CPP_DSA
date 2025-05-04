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
    int loopLength(Node *head) {
        Node *slow,*fast;
        slow = head;
        fast = head;
       while(fast!=nullptr && fast->next!=nullptr)
       {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
            {
                int cnt = 1;
                slow = slow->next;
                while(slow!=fast)
                {
                    slow=slow->next;
                    cnt++;
                }
                return cnt;
            }
       }
       return 0; 
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
    l.head->next->next->next->next->next = l.head->next;
    cout<<l.loopLength(l.head);
}