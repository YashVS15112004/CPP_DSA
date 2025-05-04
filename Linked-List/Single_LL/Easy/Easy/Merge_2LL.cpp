#include<bits/stdc++.h>
using namespace std;
class ListNode
{
    public:
    int val;
    ListNode *next;
    ListNode() {val=0;next=nullptr;}
    ListNode(int data) {this->val = data;this->next=nullptr;}
};
class List : public ListNode
{
    public:
    ListNode *head;
    List() {head = nullptr;}
    void add(vector<int> &nums)
    {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            ListNode *newNode = new ListNode(nums[i]);
            if(i==0 || head==nullptr) head = newNode;
            else
            {
                ListNode *temp = head;
                while(temp->next!=nullptr) temp = temp->next;
                temp->next = newNode;
            }
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
       ListNode *p1,*p2,*p3,*p4; 
       p2 = nullptr;
       p4 = nullptr;
       int head = 0;
       p1 = list1;
       p3 = list2;
       if(p1==NULL && p3==NULL) return nullptr;
       else if(p1==NULL) return list2;
       else if(p3==NULL) return list1;
       if(p1->val<=p3->val) head = 1;
       else head = 3; 
       while(p1!=nullptr && p3!=nullptr)
       {
            if(p1->val > p3->val)
            {
                if(p3->next!=nullptr && p3->next->val<=p1->val)
                {
                    p4 = p3;
                    p3 = p3->next;
                }
                else
                {
                    p4 = p3;
                    p3 = p3->next;
                    p4->next = p1;
                }
            }
            else if(p1->val < p3->val)
            {
                if(p1->next!=nullptr && p1->next->val<=p3->val)
                {
                    p2 = p1;
                    p1 = p1->next;
                }
                else
                {
                    p2 = p1;
                    p1 = p1->next;
                    p2->next = p3;
                }
            }
            else
            {
                if(p4!=nullptr && (p4->next==p3 || p4==p3))
                {
                    p4 = p3;
                    p3 = p3->next;
                    p4->next = p1;
                    p2 = p1;
                }
                else
                {
                    p2 = p1;
                    p1 = p1->next;
                    p2->next = p3;
                    p4 = p3;
                }
            }
       }
       if(head==1) return list1;
       else return list2;
    }
    void traversal()
    {
        ListNode *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    vector<int> nums1 = {4,6,34,38,41,47,55,55,96};
    vector<int> nums2 = {27,28,35,56,59,70,96};
    List l1,l2,l3;
    l1.add(nums1);
    l2.add(nums2);
    l3.head = l3.mergeTwoLists(l1.head,l2.head);
    l3.traversal();
}