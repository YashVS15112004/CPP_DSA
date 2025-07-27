#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    // Function to find the path from the
    // root to a given node with value 'x'
    bool getPath(TreeNode* root, vector<int>& arr, int x) {
        // Base case: If the current
        // node is null, return false
        if (!root) {
            return false;
        }

        // Add the current node's
        // value to the path vector
        arr.push_back(root->val);

        // If the current node's value is equal
        // to the target value 'x', return true
        if (root->val == x) {
            return true;
        }

        // Recursively search for the target value
        // 'x' in the left and right subtrees
        if (getPath(root->left, arr, x)
            || getPath(root->right, arr, x)) {
            return true;
        }

        // If the target value 'x' is not found
        // in the current path, backtrack
        arr.pop_back();
        return false;
    }

    // Function to find and return the path from
    // the root to a given node with value 'B'
    vector<int> solve(TreeNode* A, int B) {
        // Initialize an empty
        // vector to store the path
        vector<int> arr;

        // If the root node is null,
        // return the empty path vector
        if (A == NULL) {
            return arr;
        }

        // Call the getPath function to find
        // the path to the node with value 'B'
        getPath(A, arr, B);

        // Return the path vector
        return arr;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to leaf with value " <<
        targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }

    return 0;
}
        