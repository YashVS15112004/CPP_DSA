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
void PreOrder(Node *node)
{
    if(node==NULL) return;
    cout<<node->data<<" ";
    PreOrder(node->left);
    PreOrder(node->right);
}
int main()
{
    Node *root  = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    PreOrder(root);
}