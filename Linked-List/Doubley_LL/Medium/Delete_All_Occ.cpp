#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
    Node()
    {
        prev = nullptr;
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
    }
};
class DLL : public Node
{
    
    public:
    Node *head;
    Node *tail;
    DLL(){head = nullptr;}
    DLL(int data)
    {
        this->head = new Node(data);
    }
    void addNode(int data) //At End
    {
        Node *newNode = new Node(data);
        if(head == nullptr)
        {
            head = newNode;
            tail = head;
            return;
        }
        Node *p1 = head;
        while(p1->next!=nullptr) p1=p1->next;
        p1->next = newNode;
        newNode->prev = p1;
        tail = newNode;
    }
    void addArray(vector<int> nums) //At End
    {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            Node *newNode = new Node(nums[i]);
            if(head == nullptr) head = newNode;
            else 
            {
                Node *p1 = head;
                while(p1->next!=nullptr) p1=p1->next;
                p1->next = newNode;
                newNode->prev = p1;
                tail = newNode;
            }
        }
    }
    void traversal()
    {
        Node *ptr = head;
        while(ptr!=nullptr)
        {
            cout<<ptr->data<<"<-->";
            ptr=ptr->next;
        }
        cout<<"NULL"<<endl;
    }
    void rev_traversal()
    {
        Node *ptr = tail;
        while(ptr!=nullptr)
        {
            cout<<ptr->data<<"<-->";
            ptr=ptr->prev;
        }
        cout<<"NULL"<<endl;
    }
    Node* deleteAllOccurOfX(Node* head, int x)
    {
    Node *p1 = head;
    while(p1!=nullptr)
    {
        if(p1==head && p1->data==x)
        {
            Node *p2 = p1;
            head = head->next;
            head->prev = nullptr;
            p1 = head;
        }
        else if(p1->next==nullptr && p1->data==x)
        {
            Node *p2 = p1;
            p1 = p1->prev;
            p2->prev = nullptr;
            p1->next = nullptr;
            delete p2;
            break;
        }
        else if(p1->data == x)
        {
            Node *p2 = p1;
            p2->prev->next = p2->next;
            p2->next->prev = p2->prev;
            p1 = p2->next;
            p2->next = nullptr;
            p2->prev = nullptr;
            delete p2;
        }
        else p1 = p1->next;
    }
    return head;
    }
};
int main()
{
    vector<int> nums = {9,1,3,4,5,1,8,4};
    DLL dll;
    dll.addArray(nums);
    dll.traversal();
    dll.head = dll.deleteAllOccurOfX(dll.head,9);
    dll.traversal();
}