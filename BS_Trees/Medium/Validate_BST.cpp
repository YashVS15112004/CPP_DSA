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
void levelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root); 
    while (!q.empty()) {
        Node* current = q.front();
        q.pop(); 
        cout << current->val << " ";
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}
bool isValid(Node* root,long minv,long maxv)
{
    if(root==NULL) return true;
    if(root->val>=maxv || root->val<=minv) return false;
    return isValid(root->left,minv,root->val) && isValid(root->right,root->val,maxv);
}
bool isValid_Opt(Node* root)
{ 
    return isValid(root,LONG_MIN,LONG_MAX);
}
void traverse(Node*root,vector<long long>&ans)
{
    if(root==NULL) return;
    traverse(root->left,ans);
    ans.push_back(root->val);
    traverse(root->right,ans);
}
bool isValidBST(Node* root) {
    vector<long long> ans;
    traverse(root,ans);
    return is_sorted(ans.begin(),ans.end())&&adjacent_find(ans.begin(),ans.end())==ans.end();
}
int main()
{
    Node *root = new Node(32);
    root->left = new Node(26);
    root->right = new Node(47);
    root->right->right = new Node(56);
    root->left->left = new Node(14);
    root->left->left->right = new Node(27);
    cout<<isValid_Opt(root);
}