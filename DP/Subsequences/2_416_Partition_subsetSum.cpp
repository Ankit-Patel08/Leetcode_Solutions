/*
link -> https://leetcode.com/problems/partition-equal-subset-sum/description/
*/

// recursion + memoization
class Solution {
    private:
    bool isposs(vector<int>& nums, int idx, int sum, vector<vector<int>>&dp){
        if(sum == 0) return true;
        if(sum < 0 || idx >= nums.size()) return false;

        if(dp[idx][sum] != -1) return dp[idx][sum];

          bool take  = isposs(nums, idx+1, sum-nums[idx], dp);

          bool nottake =  isposs(nums, idx+1, sum, dp);

        return dp[idx][sum] = take || nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0){
            return false;
        }else{
            int target = total/2;
            vector<vector<int>>dp(n+1,vector<int>(target+1, -1));
            return isposs(nums, 0, target, dp);
        }
    }
};