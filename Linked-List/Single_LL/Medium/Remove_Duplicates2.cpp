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
class LinkedList : Node
{
    public:
    Node *head;
    LinkedList(){head = NULL;}
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
    void add_Begin(int data)
    {
        Node *temp = head;
        Node *newnode = new Node(data);
        if(head==NULL)
        {
            head = newnode;
            return;
        }
        head = newnode;
        head->next = temp;
    }
    void add_pos(int data,int pos)
    {
        Node *temp = head;
        Node *newnode = new Node(data);
        if(head==NULL)
        {
            head = newnode;
            return;
        }   
        int cnt = 1;
        while(cnt<pos-1)
        {
            cnt++;
            temp=temp->next;
        }
        if(pos==1)
        {
            head = newnode;
            head->next = temp;
            return;
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
    }
    void insert_BeforeVal(int data,int val)
    {
        Node *temp = head;
        if(temp->data == val)
        {
            add_Begin(val);
            return;
        }
        else
        {
            Node *newnode = new Node(data);
            while(temp->next->data!=val) temp=temp->next;
            Node *ptr = temp;
            temp = temp->next;
            ptr->next = newnode;
            newnode->next = temp;
        }
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
    int length()
    {
        Node *temp = head;
        int cnt = 0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    bool search(int target)
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            if(temp->data == target) return true;
            temp=temp->next;
        }
        return false;
    }
    void delete_beg()
    {
        Node *temp = head;
        if(temp==NULL) return;
        head = head->next;
        delete temp;
    }
    void delete_end()
    {
        Node *temp = head;
        if(temp==NULL) return;
        while(temp->next->next!=NULL) temp=temp->next;
        Node *ptr = temp;
        temp = temp->next;
        ptr->next = NULL;
        delete temp;
    }
    void delete_pos(int pos)
    {
        Node *temp = head;
        if(temp==NULL) return;
        int cnt = 1;
        while(cnt<pos-1)
        {
            cnt++;
            temp = temp->next;
        }
        if(pos==1) 
        {
            delete_beg();
            return;
        }
        Node *ptr = temp;
        temp = temp->next;
        ptr->next = temp->next;
        delete temp;
    }
    void delete_val(int target)
    {
        Node *temp = head;
        if(temp->data == target)
        {
            delete_beg();
            return;
        }
        else
        {
            while(temp->next->data!=target) temp = temp->next;
            Node *ptr = temp;
            temp = temp->next;
            ptr->next = temp->next;
            delete temp;
        }
    }
    Node* deleteDuplicates() {
        Node *p1,*p2,*p3;
        p1 = nullptr;
        p2 = head;
        if(p2==nullptr || p2->next==nullptr) return p2;
        //if(p2->data==p2->next->data && p2->next->next==nullptr) return nullptr;
        p3 = p2->next;
        while(p3!=nullptr)
        {
            if(p2->data!=p3->data)
            {
                p1 = p2;
                p2 = p3;
                p3 = p3->next;
            }
            else if(p2->data==p3->data)
            {
                p3 = p3->next;
                if(p3!=nullptr && p2!=head && p2->data!=p3->data)
                {
                    p1->next = p3;
                    p2 = p3;
                    if(p3!=nullptr) p3 = p3->next;
                }
                else if(p3!=nullptr && p2==head && p2->data!=p3->data)
                {
                    head = p3;
                    p2 = p3;
                    if(p3!=nullptr) p3 = p3->next;
                }
                else if(p3==nullptr && p2==head)
                {
                    head = nullptr;
                }
                else if(p3==nullptr) p1->next = p3;
            }
        }
        return head;
    }
};
int main()
{
    LinkedList list;
    list.addNode(1);
    list.addNode(1);
    list.traversal();
    list.head = list.deleteDuplicates();
    list.traversal();
}