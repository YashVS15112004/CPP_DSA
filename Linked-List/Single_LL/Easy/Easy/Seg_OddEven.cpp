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
class LinkedList : public Node
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
            }
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
    void OddEvenList()
    {
    Node *ptr,*t;
    ptr = head->next;
    t = ptr->next;
    int i = 2;
    int j = 3;
    while(ptr!=nullptr)
    {
        if(j%2!=0)
        {
            swap(ptr->data,t->data);
            i++;
            j++;
            ptr = ptr->next;
        }
        else if(j%2==0)
        {
            t = ptr->next;
            if(t==nullptr) break;
            for(int k=i;i<j;i++)
            {
                swap(ptr->data,t->data);
                t = t->next;
            }
            t = t->next;
            j++;
        }
    }
    return;
}
};
int main()
{
    vector<int> nums = {1,2,3,4,5};
    LinkedList l;
    l.addArray(nums);
    l.traversal();
    l.OddEvenList();
    l.traversal();
}