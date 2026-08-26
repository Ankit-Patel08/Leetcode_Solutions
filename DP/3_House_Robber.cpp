/*
link ->  https://leetcode.com/problems/house-robber/
*/


// RECURSION + MEMIOZATION

#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    int maxRob(vector<int>&nums, vector<int>&dp, int idx){
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];

        if(dp[idx] != -1) return dp[idx];

        int takingIdx = nums[idx]+ maxRob(nums, dp, idx-2);

        int notTakingIdx = 0+ maxRob(nums, dp, idx-1);

        return dp[idx] = max(takingIdx, notTakingIdx);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        
        return maxRob(nums, dp, n-1);

    }
};