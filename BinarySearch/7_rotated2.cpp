/*
link ->   https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/\

*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l);
            if(nums[mid] == target) return true;
            else if(nums[l] == nums[mid] && nums[mid] == nums[r]){  // this is extra than the previous rotated because of the duplication element
                l++;
                r--;
            }
            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }else{
                if(nums[mid] <= target && target <= nums[r]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
        }
        return false;
    }
};