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
void Ancestors(Node* root,Node *target,set<Node*> &anc,bool &flag)
{
    if(root==NULL || flag) return;
    if(root==target)
    {
        anc.insert(root);
        flag = !flag;
        target = NULL;
        return;
    }
    Ancestors(root->left,target,anc,flag);
    if(flag)anc.insert(root);
    Ancestors(root->right,target,anc,flag);
    if(flag)anc.insert(root);
}
Node* lowestCommonAncestor(Node* root,Node* p,Node* q) 
{
    set<Node*> anc1,anc2;
    bool flag = false;
    Ancestors(root,p,anc1,flag);
    flag = false;
    Ancestors(root,q,anc2,flag);
    int i=0,j=0,n=anc1.size(),m=anc2.size();
    Node *ans = NULL;
    auto it1 = anc1.begin(),it2 = anc2.begin();
    while(it1!=anc1.end() && it2!=anc2.end())
    {
        if(it1!=anc2.end() && it2!=anc2.end() && *it1==*it2) ans = *it2;
        it1++;
        it2++;
    }
    return ans;
}
int main()
{
    Node *root = new Node(-1);
    root->left =  new Node(0);
    root->left->left = new Node(-2);
    Node*p = root->left->left->left = new Node(8);
    root->left->right = new Node(4);
    root->right = new Node(3);
    Node *anc = lowestCommonAncestor(root,p,root);
    cout<<anc->val;
}