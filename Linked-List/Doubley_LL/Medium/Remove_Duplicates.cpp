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
    Node * removeDuplicates(struct Node *head)
    {
        Node *p1 = head;
        Node *p2 = p1->next;
        while(p2!=nullptr)
        {
            if(p1->data == p2->data)
            {
                Node *p3 = p2;
                p1->next = p2->next;
                if(p2->next!=nullptr) p2->next->prev = p1;
                p3->next = nullptr;
                p3->prev = nullptr;
                delete p3;
                p2 = p1->next;
            }
            else
            {
                p1 = p2;
                p2 = p2->next;
            }
            
        }
        return head;
    }
};
int main()
{
    vector<int> nums = {1,2,2,3,3,4,4};
    DLL dll;
    dll.addArray(nums);
    dll.head = dll.removeDuplicates(dll.head);
    dll.traversal();
}