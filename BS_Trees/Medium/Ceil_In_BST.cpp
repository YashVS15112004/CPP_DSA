#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    int data;
    Node* right;
    Node(){left=NULL;data=0;right=NULL;}
    Node(int val){this->data=val;left=NULL;right=NULL;}
};
int findCeil(Node* root, int input) {
    Node *node = NULL;
    while(root)
    {
        if(root->data-input>0) node = root;
        if(root->data==input) break;
        root = (root->data<input)?root->right:root->left;
    }
    if(root) return root->data;
    else if(node) return node->data;
    return -1;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->right = new Node(8);
    root->right = new Node(11);
    cout<<findCeil(root,6);
}