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
Node* lowestCommonAncestor(Node* root,Node* p,Node* q) 
{
    if(root==NULL) return NULL;
    while(root)
    {
        if((p->val<root->val && q->val>root->val) || (p->val>root->val && q->val<root->val)) return root;
        if((p->val==root->val) || (q->val==root->val)) return root;
        root = (p->val<root->val && q->val<root->val)?root->left:root->right;
    }
    return root;       
}
int main()
{
    Node *root = new Node(2);
    Node *p = root->left = new Node(1);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    Node *q = root->left->right->right = new Node(5);
    Node *lca = lowestCommonAncestor(root,p,q);
    cout<<lca->val<<endl;
}