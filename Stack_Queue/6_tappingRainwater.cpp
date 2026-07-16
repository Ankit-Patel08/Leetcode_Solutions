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







 /* here no need to maintain the left and right max heights in a separate array,
  we can just maintain two variables to store the max heights from left and right side.
  This will reduce the space complexity from O(n) to O(1).
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = 0;
        int rightmax = 0;
        int totalwater = 0;
        int l = 0;
        int r = height.size()-1;
        while(l < r){   // we will choose to go from the less heigh side to avoid storing extra
            if(height[l] <= height[r]){             // max heights 
                if(leftmax > height[l])
                   totalwater += leftmax-height[l];
                else 
                   leftmax = height[l];

              l++;
            }else{
                if(rightmax > height[r]){
                    totalwater += rightmax-height[r];
                }
                else{
                   rightmax = height[r];
                }
                r--;
                }
            }
        return totalwater;
    }
};