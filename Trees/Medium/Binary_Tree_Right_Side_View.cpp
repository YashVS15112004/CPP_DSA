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
void view(Node* root,vector<int> &ans,int level,int& mh)
{
    mh = max(mh,level);
    if(root==NULL) 
    {
        --level;
        return;
    }
    if(level==mh)ans.push_back(root->val);
    view(root->right,ans,level+1,mh);
    view(root->left,ans,level+1,mh);
}
vector<int> rightSideView(Node* root) {
    vector<int> ans;
    int level = 0,mh = 0;
    view(root,ans,level,mh);
    return ans;    
}
int main()
{
    Node *root = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(3);
    root->right->right = new Node(5);
    root->right->left->left = new Node(2);
    root->right->right->right = new Node(6);
    vector<int> ans = rightSideView(root);
    for(auto it:ans) cout<<it<<" ";
}