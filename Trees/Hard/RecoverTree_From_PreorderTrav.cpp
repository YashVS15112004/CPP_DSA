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
    vector<vector<int>> ans; 
    if (root == nullptr) {
        return ans; 
    }
    queue<Node*> q; 
    q.push(root); 
    while (!q.empty()) {
        int size = q.size(); 
        vector<int> level; 
        for (int i = 0; i < size; i++) {
            Node* node = q.front(); 
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
void printVector(vector<vector<int>>& vec) {
for(auto it:vec)
{
    for(auto it1:it) cout<<it1<<" ";
    cout << endl;
}
}
string s;
int idx = 0, level = 0;
void helper(Node* parent, int lvl) {
        while (idx < s.length() && lvl == level) {
            int num = 0;
            while (idx < s.length() && isdigit(s[idx])) {
                num = num * 10 + (s[idx++] - '0');
            }
            Node* node = new Node(num);
            if (!parent->left)
                parent->left = node;
            else
                parent->right = node;
            level = 0;
            while (idx < s.length() && s[idx] == '-') {
                level++;
                idx++;
            }
            helper(node, lvl + 1);
        }
}
Node* recoverFromPreorder(string traversal) {
        s = traversal;
        Node* node = new Node(-1);
        helper(node, 0);
        return node->left;
    }
int main()
{
    string traversal = "1-2--3--4-5--6--7";
    Node *root = recoverFromPreorder(traversal);
    vector<vector<int>> ans = levelOrder(root);
    printVector(ans);
}