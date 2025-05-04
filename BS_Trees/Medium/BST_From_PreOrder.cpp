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
void preoder(Node *root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    preoder(root->left);
    preoder(root->right);
}
Node* build(vector<int>& preoder,int &i,int bound)
{
    if(i==preoder.size() || preoder[i]>bound) return NULL;
    Node * root = new Node(preoder[i++]);
    root->left = build(preoder,i,root->val);
    root->right = build(preoder,i,bound);
    return root;
}
Node* bstFromPreorder(vector<int>& preorder) 
{
    int i = 0;
    return build(preorder,i,INT_MAX);
}
int main()
{
    vector<int> preorder = {8,5,1,7,10,12};
    Node * root = bstFromPreorder(preorder);
    preoder(root);
}