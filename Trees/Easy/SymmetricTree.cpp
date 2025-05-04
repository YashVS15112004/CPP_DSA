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
bool cmp(Node* n1,Node *n2)
{
    if(n1==NULL && n2==NULL) return true;
    if(n1==NULL || n2==NULL) return false;
    return ((n1->val==n2->val) && cmp(n1->left,n2->right) && cmp(n1->right,n2->left));
}
bool isSymmetric(Node* root) 
{
    if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
    if(root->left==NULL || root->right==NULL) return false;
    Node *l = root->left;
    Node *r = root->right;
    return cmp(l,r);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    cout<<isSymmetric(root);
}