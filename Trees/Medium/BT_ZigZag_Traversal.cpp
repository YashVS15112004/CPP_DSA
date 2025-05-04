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
vector<vector<int>> zigzagLevelOrder(Node* root)
{
    // Video dekhna
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    bool direction = true;
    while(!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            Node * node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        if(!direction) reverse(level.begin(),level.end());
        direction  = !direction;
        ans.push_back(level);
    }
    return ans;   
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->right = new Node(5);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for(auto it:ans) 
    {
        for(auto itr:it) cout<<itr<<" ";
        cout<<endl;
    }
}