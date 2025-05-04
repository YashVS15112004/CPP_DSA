#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
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
    // Function to build a binary tree
    // from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        // Create a map to store indices
        // of elements in the inorder traversal
        map<int, int> inMap;
        // Populate the map with indices
        // of elements in the inorder traversal
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }
        // Call the private helper function
        // to recursively build the tree
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
private:
    // Recursive helper function to build the tree
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
            vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
                // Base case: If the start indices 
                // exceed the end indices, return NULL
                if(preStart > preEnd || inStart > inEnd){
                    return NULL;
                }
                // Create a new TreeNode with value
                // at the current preorder index
                TreeNode* root = new TreeNode(preorder[preStart]);
                // Find the index of the current root
                // value in the inorder traversal
                int inRoot = inMap[root->val];
                // Calculate the number of
                // elements in the left subtree
                int numsLeft = inRoot - inStart;
                // Recursively build the left subtree
                root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, 
                                inorder, inStart, inRoot - 1, inMap);
                // Recursively build the right subtree
                root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, 
                                inorder, inRoot + 1, inEnd, inMap);
                // Return the current root node
                return root;
            }
};
// Function to print the
// inorder traversal of a tree
void printInorder(TreeNode* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
// Function to print the 
// given vector
void printVector(vector<int>&vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    cout << "Inorder Vector: ";
    printVector(inorder);
    cout << "Preorder Vector: ";
    printVector(preorder);
    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);
    cout << "Inorder of Unique Binary Tree Created: "<< endl;
    printInorder(root);
    cout << endl;
    return 0;
}
                            
                        