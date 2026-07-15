/*
link -> https://leetcode.com/problems/trapping-rain-water/
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftHeight(n);  // store the max height from the left index
        vector<int>rightHeight(n);  // store the max height from the right index

        leftHeight[0] = height[0];
        for(int i = 1; i<n; i++){
            leftHeight[i] = max(height[i],leftHeight[i-1]);
        }

        rightHeight[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            rightHeight[i] = max(height[i], rightHeight[i+1]);
        }

      int totalWater = 0;
      for(int i = 1; i<n; i++){
        totalWater += (min(leftHeight[i], rightHeight[i]) - height[i]);
      }

      return totalWater;
    }
};