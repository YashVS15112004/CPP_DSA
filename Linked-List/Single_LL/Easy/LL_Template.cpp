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
    Node *head;
    public:
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
};
int main()
{
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(6);
    list.traversal();
    list.insert_BeforeVal(5,6);
    list.traversal();
}