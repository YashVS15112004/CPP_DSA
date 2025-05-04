#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            root = root->left;
        }
    }
    int next() {
        TreeNode* currNode = st.top();
        st.pop();
        if (currNode->right != NULL) {
            TreeNode* temp = currNode->right;
            while (temp != NULL) {
                st.push(temp);
                temp = temp->left;
            }
        }
        return currNode->val;
    }
    bool hasNext() {
        return !st.empty();
    }
};
int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    BSTIterator iter(root);
    while (iter.hasNext()) {
        cout << iter.next() << " ";
    }
    return 0;
}
