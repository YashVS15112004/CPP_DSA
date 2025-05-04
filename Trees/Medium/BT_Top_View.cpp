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
void view(Node* root,int &index,int &level,map<int,pair<int,Node*>> &mp)
{
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            Node *node = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(mp[idx].second==NULL || mp[idx].first>level)
            mp[idx] = {level,node};
            if(node->left) q.push({node->left,idx-1});
            if(node->right) q.push({node->right,idx+1});
            level++;
        }
    }    
}
vector<int> topView(Node *root)
{
    vector<int> ans;
    int index=0,level=0;
    map<int,pair<int,Node*>> mp;
    view(root,index,level,mp);
    for(auto it:mp) ans.push_back(it.second.second->val);       
    return ans;
}
int main()
{
    Node *root = new Node(10);
    root->right = new Node(30);
    root->right->left = new Node(90);
    root->right->right = new Node(100);
    root->left = new Node(20);
    root->left->right = new Node(60);
    root->left->left = new Node(40);
    vector<int> ans = topView(root);
    for(auto it:ans) cout<<it<<" ";
}