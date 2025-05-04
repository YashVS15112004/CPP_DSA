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
Node* segregate(Node* head) {
        unordered_map <int,int> mp;
        Node *p1 = head;
        while(p1!=nullptr)
        {
            mp[p1->data]++;
            p1 = p1->next;
        }
        p1 = head;
        int zc = mp[0];
        int oc = mp[1];
        int tc = mp[2];
        int n = zc + oc + tc;
        while(zc>0)
        {
            p1->data = 0;
            p1 = p1->next;
            zc--;
        }
        while(oc>0)
        {
            p1->data = 1;
            p1 = p1->next;
            oc--;
        }
        while(tc>0)
        {
            p1->data = 2;
            p1 = p1->next;
            tc--;
        }
        return head;
    }
};
int main()
{
    // STriver
}