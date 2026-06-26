/*
Given the root of a binary tree, return the size of the tree.
The size of a binary tree is the total number of nodes in the tree.

link -> https://www.geeksforgeeks.org/problems/size-of-binary-tree/1

*/




struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



// MTHOD 1

class Solution {
  public:
    int getSize(Node* root) {
        // code here
      //  if(node == nullptr) return 0;
        queue<Node*>q;
        q.push(root);
        
        int count = 0;
        
        while(!q.empty()){
            Node *current = q.front();
            q.pop();
            count++;
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        return count;
    }
};


// METHOD 2 

class Solution {
    private:
    void countnode(Node *root,int &count){
        if(root == nullptr)return;
        count++;
        countnode(root->left,count);
        countnode(root->right,count);
    }
  public:
    int getSize(Node* root) {
        int count = 0;
        countnode(root,count);
        return count;
    }
};



// METHOD 3 

class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(root == nullptr) return 0;
        
        return 1+getSize(root->left)+getSize(root->right);
    }
};