#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition of the Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find parent nodes and the target node
Node* Parent(Node* node, unordered_map<Node*, Node*>& parent, int target) {
    queue<Node*> q;
    q.push(node);
    Node* Target = nullptr;
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->data == target)
            Target = current;
        if (current->left) {
            parent[current->left] = current;
            q.push(current->left);
        }
        if (current->right) {
            parent[current->right] = current;
            q.push(current->right);
        }
    }
    return Target;
}

// Function to calculate minimum time to burn the tree
int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> parent;
    unordered_map<Node*, int> visited;
    Node* Target = Parent(root, parent, target);
    int time = 0;
    queue<Node*> q;
    q.push(Target);
    visited[Target] = 1;
    while (!q.empty()) {
        int size = q.size();
        bool burned = false;
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            if (temp->left && visited.find(temp->left) == visited.end()) {
                q.push(temp->left);
                visited[temp->left] = 1;
                burned = true;
            }
            if (temp->right && visited.find(temp->right) == visited.end()) {
                q.push(temp->right);
                visited[temp->right] = 1;
                burned = true;
            }
            if (parent[temp] && visited.find(parent[temp]) == visited.end()) {
                q.push(parent[temp]);
                visited[parent[temp]] = 1;
                burned = true;
            }
        }
        if (burned)
            time++;
    }
    return time;
}

// Main function to create a tree and test the minTime function
int main() {
    /*
        Sample Tree:
              1
             / \
            2   3
           / \   \
          4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int target = 2;
    cout << "Minimum time to burn the tree from target node " << target << " is: " << minTime(root, target) << endl;
    
    return 0;
}
