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
int depth(Node* root,int& diam)
{
    if(root == NULL) return 0;
    int l = depth(root->left,diam);
    int r = depth(root->right,diam);
    diam = max(diam,l+r);
    return 1+max(l,r);
}
int diameterOfBinaryTree(Node* root) {
    int diam = 0;
    depth(root,diam);
    return diam;
}
int main()
{
    Node *root  = new Node(1);
    root->left = new Node(2);
    cout<<diameterOfBinaryTree(root);
}