/*
link -> https://leetcode.com/problems/max-consecutive-ones-iii/
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n = nums.size();
       int count = 0;
       int left = 0;
       int longestConsecOnes= 0;
       for(int right = 0; right < n;  right++){
        if(nums[right] == 0) count++;
        while(count > k){
            if(nums[left] == 0) count--;
            left++;
        }
        longestConsecOnes = max(longestConsecOnes, right-left+1);
       }
       return longestConsecOnes;
    }
};


  // FOLLOW THIS PATTERN FOR SLIDING WINDOW PROBLEMS 
/*
Add right
   ↓
Did adding it make window invalid?
   ↓
YES → shrink from left
   ↓
Window is valid
   ↓
Calculate length
*/