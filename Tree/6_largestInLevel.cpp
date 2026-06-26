/*
Given a binary tree, find the largest value in each level.

link -> https://www.geeksforgeeks.org/problems/largest-value-in-each-level/1

*/

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        queue<Node*>q;
        q.push(root);
        vector<int>ans;
        
        while(!q.empty()){
            // Node *current = q.front();
            // q.pop();
            
            int sz = q.size();
            
            int maxi = INT_MIN;
            for(int i = 0; i < sz; i++){
                Node *current = q.front();
                q.pop();
                maxi = max(maxi,current->data);
                
                if(current->left != nullptr) q.push(current->left);
                if(current->right != nullptr) q.push(current->right);
            }
            ans.push_back(maxi);
        }
        return ans;
        
    }
};