#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    int val;
    Node* right;
    Node(){left=NULL;val=0;right=NULL;}
    Node(int val){this->val=val;left=NULL;right=NULL;}
};
void view(Node* root,int x,int y,map<int,multiset<pair<int,multiset<int>>>> &mp)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        Node *node = q.front();
        q.pop();
        for(int i=0;i<size;i++)
        {
            pair<int,multiset<int>> p;
            p.first = y;
            p.second.insert(node->val);   
            mp[x].insert(p);
            if(node->left)
            view(root->left,x-1,y+1,mp);
            if(node->right)
            view(root->right,x+1,y+1,mp);
        }
    } 
}
vector<vector<int>> verticalTraversal(Node* root) {
    vector<vector<int>> ans;
    int x=0,y=0;
    map<int,multiset<pair<int,multiset<int>>>> mp;
    view(root,x,y,mp);  
    for(auto it:mp)
    {
        vector<int> temp;
        for(auto itr:it.second)
        for(auto it2:itr.second) temp.push_back(it2);
        ans.push_back(temp); 
    }     
    return ans;
}
int main()
{
    Node *root = new Node(3);
    root->right = new Node(4);
    root->right->left = new Node(2);
    root->left = new Node(1);
    root->left->right = new Node(2);
    root->left->left = new Node(0);
    vector<vector<int>> ans = verticalTraversal(root);
    for(auto it:ans)
    {
        for(auto itr:it) cout<<itr<<" ";
        cout<<endl;
    }
}