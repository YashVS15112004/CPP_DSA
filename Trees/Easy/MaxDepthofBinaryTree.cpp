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
int MaxDepth(Node *root)
{
    if(root == NULL) return 0;
    int lh = MaxDepth(root->left);
    int rh = MaxDepth(root->right);
    return 1 + max(lh, rh);
}
int main()
{
    Node *root  = new Node(10);
    root->right = new Node(30);
    cout<<MaxDepth(root);
}