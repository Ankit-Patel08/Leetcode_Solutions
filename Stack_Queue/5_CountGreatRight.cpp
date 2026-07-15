/*
link -> https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1
*/


class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
        // code here
        int n = indices.size();
        int m = arr.size();
        
        int count = 0;
        
        vector<int>ans;
        
        for(int i = 0; i<n; i++){
            for(int j = indices[i]+1; j < m; j++){
                if(arr[j] > arr[indices[i]]) count++;
            }
            ans.push_back(count);
            count = 0;
        }
        return ans;
    }
};



