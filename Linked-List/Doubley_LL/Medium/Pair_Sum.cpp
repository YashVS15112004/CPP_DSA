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
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        Node *p1 = head;
        Node *p2 = tail;
        // while(p1!=nullptr)
        // {
        //     p2 = p1;
        //     p1 = p1->next; 
        // } For TAIL
        //p1 = head;
        while(p1->data<p2->data)
        {
            if(p1->data+p2->data == target)
            {
                pair<int,int> p = {p1->data,p2->data};
                ans.push_back(p);
                p1 = p1->next;
                p2 = p2->prev;
            }
            else if(p1->data+p2->data > target) p2 = p2->prev;
            else p1 = p1->next;
        }
        return ans;
    }
};
int main()
{
    vector<int> nums = {1,2,4,5,6,8,9};
    DLL dll;
    dll.addArray(nums);
    vector<pair<int,int>> ans = dll.findPairsWithGivenSum(dll.head,7);
    for(auto it:ans) cout<<it.first<<","<<it.second<<endl;
}