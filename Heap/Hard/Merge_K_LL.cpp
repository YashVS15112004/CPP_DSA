#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* createLinkedList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout<<endl;
}
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if(lists.size()<1) return nullptr;
    int n = lists.size();
    priority_queue<int,vector<int>,greater<int>> minh;
    for(int i=0;i<n;i++)
    {
        ListNode * ptr = lists[i];
        if(ptr==nullptr) continue;
        else
        {
            while(ptr!=nullptr)
            {
                minh.push(ptr->val);
                ptr = ptr->next;
            }
        }
        delete ptr;
    }
    ListNode *head = nullptr,*ptr = nullptr;
    while(!minh.empty())
    {
        ListNode* newNode = new ListNode(minh.top());
        if(head==nullptr)
        {
            head = newNode;
            ptr = newNode;
        }
        else
        {
            ptr->next = newNode;
            ptr = ptr->next;
        }
        minh.pop();
    }
    return head;
}
int main()
{
    vector<vector<int>> l = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists;
    for (const auto& list : l) {
        lists.push_back(createLinkedList(list));
    }
    ListNode *ptr = mergeKLists(lists);
    printLinkedList(ptr);
}