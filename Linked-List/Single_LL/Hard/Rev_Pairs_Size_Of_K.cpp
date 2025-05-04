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
class LinkedList : public Node
{
    
    public:
    Node *head;
    LinkedList(){head = nullptr;}
    void addNode(int data) //At End
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
    void traversal()
    {
        Node *temp = head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
Node *reverse(Node *p3,Node *p2,int k)
    {
        Node *p0,*p5;
        if(p3->next==nullptr) return p3;
        p5 = p3->next;
        p0 = nullptr;
        int i = 1;
        while(p3!=p2 && i<=k)
        {
            p3->next = p0;
            p0 = p3;
            p3 = p5;
            i++;
            if(p5==p2) continue;
            else p5 = p5->next;
        }
        return p0;

    }
    Node* reverseKGroup(Node* head, int k) 
    {
        if(head==nullptr) return nullptr;
        Node *h,*p1,*p2,*p3,*p4,*t;
        int n = 0;
        int j = 0;
        p1 = head;
        while(p1!=nullptr)
        {
            n++;
            p1=p1->next;
        }
        p1 = head;
        p3 = head;
            int x = n/k;
            int y = x*k;
            for(int i=1;i<=y;i++)
            {
            if(i%k==0)
            {
                p2 = p1->next;
                p4 = p2;
                h = reverse(p3,p2,k);
                if(i==k) head = h;
                j++;
                if(j>1) t->next = h;
                t = h;
                while(t->next!=nullptr) t = t->next;
                p1 = p4;
                p3 = p4;
            }
            else if(i%k!=0) p1 = p1->next; 
        }
        if(n%k!=0) t->next = p4;
    return head;    
}
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
    list.head = reverseKGroup(list.head,2);
    list.traversal();
}