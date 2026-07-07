/*
link ->  https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

*/


class Solution {
    private:  
    int leftOccurance(vector<int>&arr, int target){
        int l = 0;
        int r = arr.size()-1;
        int ans = -1;
        while( l <= r){
            int mid = l + (r-l)/2;
            
            if(target == arr[mid]){
                ans = mid;
                r = mid-1;
            }else if(target < arr[mid]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }

    int rightOccurance(vector<int>&arr, int target){
        int l = 0;
        int r = arr.size()-1;
        int ans = -1;
        while( l <= r){
            int mid = l + (r-l)/2;
            
            if(target == arr[mid]){
                ans = mid;
                l = mid+1;
            }else if(target < arr[mid]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }


public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int left = leftOccurance(nums, target);
        int right = rightOccurance(nums, target);
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};