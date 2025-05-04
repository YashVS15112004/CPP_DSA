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
Node* insertIntoBST(Node* root, int val) 
{
    if(root==NULL) return new Node(val);
    Node *node = root,*node1;
    while(node)
    {
        node1 = node;
        node = (node->val>val)?node->left:node->right;
    }
    if(node1->val<val) node1->right = new Node(val);
    else node1->left = new Node(val);
    return root;
}
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
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(7);
    levelOrder(root);
    Node *node = insertIntoBST(root,5);
    cout<<endl;
    levelOrder(node);
}