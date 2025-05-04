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
int widthOfBinaryTree(Node* root) 
{
    if(!root)return 0;
        int ans=0;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int minn=q.front().second;
            int f,l;

            for(int i=0;i<size;i++){
                long long curr=q.front().second-minn;
                Node* node=q.front().first;
                q.pop();
                if(i==0)f=curr;
                if(i==size-1)l=curr;
                if(node->left)q.push({node->left,curr*2+1});
                if(node->right)q.push({node->right,curr*2+2});
               
            }
            ans=max(ans,l-f+1);

        }
        return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(1);
    root->right = new Node(1);
    root->left->left = new Node(1);
    root->left->right = new Node(1);
    root->right->right = new Node(1);
    root->right->left = new Node(1);
    root->left->right->right = new Node(1);
    root->left->right->right->left = new Node(2);
    root->left->right->right->left->left = new Node(2);
    root->left->right->right->left->right = new Node(2);
    root->left->right->right->right = new Node(2);
    root->left->right->right->right->right = new Node(2);
    root->left->right->right->right->left = new Node(2);
    root->left->right->right->left->left->left = new Node(2);
    root->left->right->right->left->right->left = new Node(2);
    root->left->right->right->right->left->right = new Node(2);
    root->left->right->right->right->right->right = new Node(2);
    cout<<widthOfBinaryTree(root);
}