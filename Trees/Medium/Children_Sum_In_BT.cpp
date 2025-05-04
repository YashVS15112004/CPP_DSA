#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    int data;
    Node* right;
    Node(){left=NULL;data=0;right=NULL;}
    Node(int data){this->data=data;left=NULL;right=NULL;}
};
void dfs(Node* root,bool &flag)
{
    if(root==NULL || !flag) return;
    if(root->left==NULL && root->right==NULL) return;
    int l = (root->left)?root->left->data:0;
    int r = (root->right)?root->right->data:0;
    if(root->data != (l+r)) flag = false;
    dfs(root->left,flag);
    dfs(root->right,flag);
}
int isSumProperty(Node* root) {
    bool flag = 1;
    dfs(root,flag);
    return ((flag)?1:0);
}
int main()
{
    Node *root = new Node(35);
    root->left = new Node(20);
    root->left->left = new Node(15);
    root->left->right = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(10);
    root->right->right = new Node(5);
    cout<<isSumProperty(root);
}