/*
link ->  https://leetcode.com/problems/find-peak-element/
*/

// there are better solution for this problem but this is the one which I gog intuitively and solved it using binary search
    class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int l = 0;
            int r = nums.size()-1;
            int n =nums.size();

            if(nums.size() == 1) return 0;

            while(l <= r){
                int mid = l+(r-l)/2;
            if(mid == 0){
            return  (nums[0]>=nums[1])? 0 : 1;
            }
            else if(mid == n-1){
                return (nums[n-1] >= nums[n-2]) ? n-1 : n-2;
            }
            else if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
                else if(nums[mid] < nums[mid+1]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            return l;
        }
    };