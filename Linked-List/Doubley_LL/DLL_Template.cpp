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
    Node *head;
    Node *tail;
    public:
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
    void Insert_Before_Head(int data)
    {
        Node *newNode = new Node(data);
        Node *ptr = head;
        newNode->next = ptr;
        head = newNode;
    }
    void Insert_Before_Tail(int data)
    {
        Node *newNode = new Node(data);
        Node *ptr = tail;
        ptr->prev->next = newNode;
        newNode->next = ptr;
        tail = newNode;
    }
    void Insert_Before_pos(int data,int pos)
    {
        Node *newNode = new Node(data);
        Node *ptr = head;
        if(pos==1) 
        {
            Insert_Before_Head(data);
            return;
        }
        else
        {
            int cnt=1;
            while(cnt<pos-1) 
            {
                ptr = ptr->next;
                cnt++;
            }
            ptr->next->prev = newNode;
            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
    void Insert_Before_Ele(int data,int target)
    {
        Node *newNode = new Node(data);
        Node *ptr = head;
        if(target==ptr->data) 
        {
            Insert_Before_Head(data);
            return;
        }
        else
        {
            int cnt=1;
            while(ptr->next->data != target) ptr = ptr->next;
            ptr->next->prev = newNode;
            newNode->prev = ptr;
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
    void delete_head()
    {
        Node *p1 = head;
        p1->next->prev = nullptr;
        head = head->next;
        delete p1;
    }
    void delete_tail()
    {
        Node *p1 = tail;
        p1->prev->next = nullptr;
        p1->prev = nullptr;
        tail = tail->prev;
        delete p1;
    }
    void delete_Kth(int pos)
    {
        int cnt = 1;
        Node *ptr = head;
        if(pos==1)
        {
            delete_head();
            return;
        }
        else
        {
            int cnt = 1;
            while(cnt<pos-1)
            {
                ptr=ptr->next;
                cnt++;
            }
            ptr->next->prev = ptr;
            ptr->next = ptr->next->next;
        }
    }
    void delete_Ele(int ele)
    {
        Node *ptr = head;
        if(ptr->data == ele)
        {
            delete_head();
            return;
        }
        else
        {
            while(ptr->next->data != ele) ptr = ptr->next;
            ptr->next->prev = ptr;
            ptr->next = ptr->next->next;
        }
    }
    void reverse()
    {
        if (head == NULL || head->next == NULL) {
        // No change is needed;
        // return the current head
        return; 
    }
     // Initialize a pointer to
     // the previous node
    Node* back = NULL;  
    // Initialize a pointer to
    // the current node
    Node* current = head;   
    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to
        // the previous node
        back = current->prev; 
        // Swap the previous and
        // next pointers
        current->prev = current->next; 
        // This step reverses the links
        current->next = back;          
        // Move to the next node
        // in the original list
        current = current->prev; 
    }
    // The final node in the original list
    // becomes the new head after reversal
    head =  back->prev;
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
};
int main()
{
    vector<int> nums = {1,2,3,4,5};
    DLL dll;
    dll.addArray(nums);
    dll.traversal();
    dll.reverse();
    dll.traversal();
}