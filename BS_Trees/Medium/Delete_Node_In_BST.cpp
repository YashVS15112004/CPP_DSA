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
void levelOrder(Node* root) {
    if (root == NULL) return;
    queue<Node*> q;
    q.push(root); 
    while (!q.empty()) {
        Node* current = q.front();
        q.pop(); 
        cout << current->val << " ";
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}
Node*findlastr(Node*root){
    if(root->right==NULL)return root;
    return findlastr(root->right);
}
Node* helper(Node*root){
    if(root->left==NULL){
        return root->right;
    }
    if(root->right==NULL)return root->left;
    Node*rc=root->right;
    Node*lastr=findlastr(root->left);
    lastr->right=rc;
    return root->left;
}
Node* deleteNode(Node* root, int key) {
            if(root==NULL)return NULL;
            if(root->val==key)return helper(root);
            Node*dummy=root;
            while(root!=NULL){
                if(root->val>=key){
                    if(root->left!=NULL && root->left->val==key){
                        root->left=helper(root->left);
                    }
                    else{
                        root=root->left;
                    }
                }
                else{
                    if(root->right!=NULL && root->right->val==key){
                        root->right=helper(root->right);
                    }
                    else{
                        root=root->right;
                    }
                }
            }
            return dummy;
}
int main()
{
    Node *root = new Node(2);
    root->left = new Node(1);
    levelOrder(root);
    cout<<endl;   
    Node *node = deleteNode(root,2);
    levelOrder(node);   
}