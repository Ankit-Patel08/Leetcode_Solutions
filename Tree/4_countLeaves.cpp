/*
Given a Binary Tree of size n, You have to count leaves in it. 

link -> https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

*/

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        if(root == nullptr) return 0;
        
        if(root->left == nullptr && root->right == nullptr) return 1;
        
        return countLeaves(root->left)+countLeaves(root->right);
        
    }
};