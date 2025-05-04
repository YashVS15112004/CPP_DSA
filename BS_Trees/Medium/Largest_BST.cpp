#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Result {
public:
    int size;
    int min, max;
    
    Result(int size, int min, int max) {
        this->size = size;
        this->min = min;
        this->max = max;
    }
};

class Solution {
private:
    Result solve(Node *root) {
        if (!root) {
            return Result(0, INT_MAX, INT_MIN);
        }
        
        Result left = solve(root->left);
        Result right = solve(root->right);
        
        if (root->data > left.max && root->data < right.min) {
            return Result(
                1 + left.size + right.size,
                min(root->data, left.min),
                max(root->data, right.max)
            );
        }
        
        return Result(max(left.size, right.size), INT_MIN, INT_MAX);
    }
    
public:
    int largestBst(Node *root) {
        return solve(root).size;
    }
};

int main() {
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    
    Solution sol;
    cout << "Size of the largest BST is: " << sol.largestBst(root) << endl;
    
    return 0;
}
