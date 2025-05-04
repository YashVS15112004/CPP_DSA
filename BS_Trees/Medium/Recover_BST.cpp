#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

public:
    void in(TreeNode* root) {
        if (root == nullptr) return;
        
        in(root->left);
        
        if (prev != nullptr && root->val < prev->val) {
            // Case 1: Violations are adjacent pairs
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else { // Case 2: Violations are not adjacent pairs
                last = root;
            }
        }
        prev = root;
        
        in(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);  // Initialize with a node that has a small value
        in(root);

        // Swap the values of the nodes that were swapped
        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};

void inorderPrint(TreeNode* root) {
    if (root == nullptr) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    // Construct a binary search tree where two nodes are swapped
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Original BST (In-order): ";
    inorderPrint(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "Recovered BST (In-order): ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
