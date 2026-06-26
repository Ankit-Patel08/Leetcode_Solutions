/*
Given a binary tree, find the sum of values of all the nodes. 

link -> https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1

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
    int sumBT(Node* root) {
        // code here
        if(root == nullptr) return 0;
        
        return root->data + sumBT(root->left) + sumBT(root->right);
    }
};