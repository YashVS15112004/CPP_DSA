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
void dfs(Node* root,vector<vector<int>> &ans,vector<int> trav)
{
    if(root==NULL) return;
    trav.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(trav);
        return;
    }
    dfs(root->left,ans,trav);
    dfs(root->right,ans,trav);
}
vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    vector<int> trav;
    dfs(root,ans,trav);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->left->left = new Node(3);
    vector<vector<int>> ans = Paths(root);
    for(auto it:ans)
    {
        for(auto it1:it) cout<<it1<<" ";
        cout<<endl;
    }
}