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
vector<vector<int>> levelOrder(Node* root) {
        // Create a 2D vector to store levels
        vector<vector<int>> ans; 
        if (root == nullptr) {
            // If the tree is empty,
            // return an empty vector
            return ans; 
        }
        // Create a queue to store nodes
        // for level-order traversal
        queue<Node*> q; 
        // Push the root node to the queue
        q.push(root); 
        while (!q.empty()) {
            // Get the size of the current level
            int size = q.size(); 
            // Create a vector to store
            // nodes at the current level
            vector<int> level; 
            for (int i = 0; i < size; i++) {
                // Get the front node in the queue
                Node* node = q.front(); 
                // Remove the front node from the queue
                q.pop(); 
                // Store the node value
                // in the current level vector
                level.push_back(node->val); 
                // Enqueue the child nodes if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            // Store the current level
            // in the answer vector
            ans.push_back(level); 
        }
        // Return the level-order
        // traversal of the tree
        return ans; 
}
// Function to print
// the elements of a vector
void printVector(vector<vector<int>>& vec) {
    // Iterate through the
    // vector and print each element
    for(auto it:vec)
    {
        for(auto it1:it) cout<<it1<<" ";
        cout << endl;
    }
}
int main()
{
    Node *root  = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    vector<vector<int>> ans = levelOrder(root);
    printVector(ans);
}