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
Node* searchBST(Node* root, int val) {
    if(root==NULL) return NULL;
    if(root->val==val) return root;
    if(val<root->val) return searchBST(root->left,val);
    else return searchBST(root->right,val);
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(7);
    Node *node = searchBST(root,2);
    cout<<node->val<<","<<node->left->val<<","<<node->right->val<<endl;
}