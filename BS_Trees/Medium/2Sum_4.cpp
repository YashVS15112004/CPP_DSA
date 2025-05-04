#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* node;
    bool forward;
public:
    BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) {};
    
    bool hasNext() {
        return node != nullptr || !s.empty();
    }
    
    int next() {
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = forward ? node->left : node->right;
            }
            else {
                node = s.top();
                s.pop();
                int nextVal = node->val;
                node = forward ? node->right : node->left;
                return nextVal;
            }
        }
        return -1;  // This is an unreachable case
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, true);  // In-order iterator (left to right)
        BSTIterator r(root, false); // Reverse in-order iterator (right to left)
        
        int i = l.next(), j = r.next();
        while (i < j) {
            int sum = i + j;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }
        return false;
    }
};

int main() {
    // Construct a sample binary search tree:
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    int target = 9;
    
    Solution sol;
    if (sol.findTarget(root, target)) {
        cout << "There are two numbers in the BST that add up to " << target << endl;
    } else {
        cout << "No two numbers in the BST add up to " << target << endl;
    }
    
    return 0;
}
