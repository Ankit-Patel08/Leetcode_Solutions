/*
find the maximum depth of the tree.

link -> https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

*/


Definition for Node
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


class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root == nullptr) return -1;
        
        return 1 + max(height(root->left), height(root->right));
    }
};