 /*
 Return the level order (BFS) traversal of a binary tree.   

 link ->  https://www.geeksforgeeks.org/problems/level-order-traversal/1

 */




   /* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        if(root == nullptr) return {};
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            Node *current = q.front();
            q.pop();
            ans.push_back(current->data);
            
            if(current->left != nullptr) q.push(current->left);
            if(current->right != nullptr) q.push(current->right);
        }
        return ans;
    }
};

