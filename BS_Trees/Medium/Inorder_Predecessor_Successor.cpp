#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    int key;
    Node* right;
    Node(){left=NULL;key=0;right=NULL;}
    Node(int val){this->key=val;left=NULL;right=NULL;}
};
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    Node *r1 = root,*r2 = root;
    // Immediate Successor
    while(r1)
    {
        if(r1->key<=key) r1 = r1->right;
        else
        {
            suc = r1;
            r1 = r1->left;
        } 
    }
    // Immediate Predecessor
    while(r2)
    {
        if(r2->key>=key) r2 = r2->left;
        else
        {
            pre = r2;
            r2 = r2->right;
        } 
    }
}
int main()
{
    Node *root = new Node(8);
    root->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right = new Node(9);
    root->right->right = new Node(10);
    Node *pre = NULL,*suc = NULL;
    int key = 8;
    findPreSuc(root,pre,suc,key);
    cout<<pre->key<<" "<<suc->key;
}