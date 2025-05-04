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
int findMaxPathSum(Node* root, int &maxi) {
        if (root == nullptr) return 0;
        int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));
        maxi = max(maxi, leftMaxPath + rightMaxPath + root->val);
        return max(leftMaxPath, rightMaxPath) + root->val;
    }
int maxPathSum(Node* root) {
    int maxi = INT_MIN;
    findMaxPathSum(root, maxi);
    return maxi;
}
int main()
{
    Node *root = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(3);
    root->right->right = new Node(5);
    root->right->left->left = new Node(2);
    root->right->right->right = new Node(6);
    cout<<maxPathSum(root);
}