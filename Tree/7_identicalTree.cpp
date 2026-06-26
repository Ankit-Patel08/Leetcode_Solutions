/*
Given two binary trees with their root nodes r1 and r2, return true if both of them are
 identical, otherwise return false.

 link->  https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1


*/


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        if(r1 == nullptr && r2 == nullptr) return true;
        if(r1 == nullptr || r2 == nullptr) return false;
        
        queue<Node*>q1;
        queue<Node*>q2;
        q1.push(r1);
        q2.push(r2);
        while(!q1.empty() && !q2.empty()){
            Node *node1 = q1.front();  // edge cases
            Node *node2 = q2.front();
            q2.pop();
            q1.pop();
            
            if(node1->data != node2->data) return false;
            
            if(node1->left != nullptr && node2->left != nullptr){
                q1.push(node1->left);
                q2.push(node2->left);
            }else if(node1->left == nullptr && node2->left == nullptr){
                // we can't tell anything about this tree may be identical after this also or
                // may not be " SO WE CAN LEAVE THIS WITH NOTHING "
            }else{
                return false;
            }
            
             if(node1->right != nullptr && node2->right != nullptr){
                q1.push(node1->right);
                q2.push(node2->right);
            }else if(node1->right == nullptr && node2->right == nullptr){
                
            }else{
                return false;
            }
            
        }
        return true;
    }
};