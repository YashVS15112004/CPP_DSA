#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    int data;
    Node* right;
    Node(){left=NULL;data=0;right=NULL;}
    Node(int data){this->data=data;left=NULL;right=NULL;}
};
bool isSameTree(Node* node1,Node* node2)
{
    if(node1==NULL && node2==NULL) return true;
    if(node1==NULL || node2==NULL) return false;
    return (node1->data == node2->data && isSameTree(node1->right,node2->right) && 
    isSameTree(node1->left,node2->left));
}
int main()
{
    Node *r1  = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);
    Node *r2  = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);
    cout<<isSameTree(r1,r2);
}