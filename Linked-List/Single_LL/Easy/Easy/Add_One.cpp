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
};
Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* current = head;
        Node* next;

        while (current != NULL) {
            next = current->next; // storing next node
            current->next = prev; // linking current node to previous
            prev = current;       // updating prev
            current = next;       // updating current
        }

        return prev;
}
Node* addOne(Node* head) {
        head = reverse(head); // reversing list to make addition easy
        Node* current = head;
        int carry = 1;
        while (carry) {
            current->data += 1; // adding one to current node

            if (current->data < 10)
                return reverse(head);
            // if no carry we can reverse back list and return it
            else
                current->data = 0;
            // else we continue with taking carry forward

            if (current->next == NULL)
                break;
            // if, end of list, we break from loop
            else
                current = current->next;
            // else we move to next node
        }
        current->next = new Node(1); // adding new node for the carried 1
        return reverse(head);
}
int main()
{
    // 8 4 2 1 4 1 1 7 6 7 7 6
    LinkedList l1;
    vector<int> nums = {8,4,2,1,4,1,1,7,6,7,7,6};
    l1.addArray(nums);
    l1.traversal();
    l1.head = addOne(l1.head);
    l1.traversal();
}