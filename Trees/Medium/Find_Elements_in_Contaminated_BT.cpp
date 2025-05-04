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
unordered_map<int,int>mp;
void modify(Node *root)
{
    if(root==NULL) return;
    if(root->left) 
    {
        root->left->val = (root->val*2)+1;
        mp[root->left->val]++;
    }
    if(root->right) 
    {
        root->right->val = (root->val*2)+2;
        mp[root->right->val]++;
    }
    modify(root->left);
    modify(root->right);
}
void FindElements(Node* root) {
    root->val = 0;
    mp[root->val]++;
    modify(root); 
}
bool find(int target) {
    if(mp[target]!=0) return true;
    mp.erase(target);
    return false;
}
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
int main()
{
    Node *root = new Node(-1);
    root->left = new Node(-1);
    root->right = new Node(-1);
    root->left->left = new Node(-1);
    root->left->right = new Node(-1);
    vector<vector<int>> ans = levelOrder(root);
    printVector(ans);
    FindElements(root);
    ans = levelOrder(root);
    printVector(ans);
    cout<<find(1)<<endl;
    cout<<find(3)<<endl;
    cout<<find(5)<<endl;
}