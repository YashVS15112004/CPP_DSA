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
        int preIndex = 0, postIndex = 0;
    
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            TreeNode* root = new TreeNode(preorder[preIndex++]);
    
            if (root->val != postorder[postIndex]) {
                root->left = constructFromPrePost(preorder, postorder);
            }
            if (root->val != postorder[postIndex]) {
                root->right = constructFromPrePost(preorder, postorder);
            }
    
            postIndex++;
            return root;
        }
};
vector<vector<int>> levelOrder(TreeNode* root) {
    // Create a 2D vector to store levels
    vector<vector<int>> ans; 
    if (root == nullptr) {
        return ans; 
    }
    queue<TreeNode*> q; 
    q.push(root); 
    while (!q.empty()) {
        int size = q.size(); 
        vector<int> level; 
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); 
            q.pop(); 
            level.push_back(node->val); 
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        ans.push_back(level); 
    }
    return ans; 
}
void printVector(vector<int>&vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}
void printVector(vector<vector<int>>& vec) {
for(auto it:vec)
{
    for(auto it1:it) cout<<it1<<" ";
    cout << endl;
}
}
int main() {
    vector<int> postorder = {4,5,2,6,7,3,1};
    vector<int> preorder = {1,2,4,5,3,6,7};
    cout << "Postorder Vector: ";
    printVector(postorder);
    cout << "Preorder Vector: ";
    printVector(preorder);
    Solution sol;
    TreeNode* root = sol.constructFromPrePost(preorder, postorder);
    cout << "Unique Binary Tree Created: "<< endl;
    vector<vector<int>> ans  = levelOrder(root);
    printVector(ans);
    return 0;
}
                            
                        