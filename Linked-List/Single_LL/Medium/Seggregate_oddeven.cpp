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
    void seggregate()
    {
        Node *p1,*p2,*p3,*p4;
        p1 = head;
        if(p1==nullptr || p1->next==nullptr || p1->next->next==nullptr) return;
        p1 = head;
        p2 = p1->next;
        p3 = p2->next;
        p4 = p3->next;
        p1->next = p3;
        p3->next = p2;
        p2->next = p4;
        int i = 1;
        while(p4->next!=nullptr)
        {
            p1 = p3;
            if(i!=1) p4=p4->next;
            p3 = p4->next;
            if(p4->next==nullptr) return;
            p4->next = p4->next->next;
            p1->next = p3;
            p3->next = p2;
            i++;
        }
    }
    int cal_GCD(int a,int b)
{
    int m = min(a,b);
    int ans = 1;
    if((a!=m && a%m==0) || (b!=m && b%m==0)) return m;
    if(m==a)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    for(int i=2;i<=m/2;i++) if(a%i==0 && b%i==0) ans = max(ans,i);
    return ans;
}
Node* insertGreatestCommonDivisors() 
{
   Node *p1,*p2;
   p1 = head;
   if(p1==nullptr || p1->next==nullptr) return head;
   p2 = p1->next;
   while(p2!=nullptr)
   {
       int a = p1->data;
       int b = p2->data;
       int c = cal_GCD(a,b);
       Node *node = new Node(c);
       p1->next = node;
       node->next = p2;
       p1 = p2;
       if(p1!=nullptr) p2 = p1->next;
   }
   return head;        
}
};
int main()
{
    LinkedList list;
    list.addNode(18);
    list.addNode(6);
    list.addNode(10);
    list.addNode(3);
    list.traversal();
    list.insertGreatestCommonDivisors();
    list.traversal();
}