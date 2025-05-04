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
void dfs(int sum,Node* root, int targetSum, bool& flag) {
    if (!root) return;
    sum = sum + root->val;
    if (root->left==NULL && root->right==NULL && sum == targetSum) flag = true;
    dfs(sum,root->left, targetSum, flag);
    dfs(sum, root->right,targetSum, flag);
}
bool hasPathSum(Node* root, int targetSum) {
    if (!root) return false;
    int sum = 0;
    bool flag = false;
    dfs(sum,root,targetSum, flag);
    return flag;
}
int main()
{
    Node *root = new Node(-2);
    root->right = new Node(-3);
    // root->right->left = new Node(13);
    // root->right->right = new Node(4);
    // root->right->right->right = new Node(1);
    // root->left = new Node(4);
    // root->left->left = new Node(11);
    // root->left->left->left = new Node(7);
    // root->left->left->right = new Node(2);
    cout<<hasPathSum(root,-5);
}