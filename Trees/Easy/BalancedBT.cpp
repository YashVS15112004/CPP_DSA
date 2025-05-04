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
int depth(Node* root)
{
    if(root==NULL) return 0;
    int lt = depth(root->left);
    int rt = depth(root->right);
    if(lt==INT_MIN || rt==INT_MIN) return INT_MIN;
    int diff = lt-rt;
    if(diff>1 || diff< -1) return INT_MIN; 
    return 1+max(lt,rt);
}
bool isBalanced(Node* root) 
{
    int diff = depth(root);
    return (diff==INT_MIN)?false:true;
}
int main()
{
    Node *root  = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);
    cout<<isBalanced(root);
}