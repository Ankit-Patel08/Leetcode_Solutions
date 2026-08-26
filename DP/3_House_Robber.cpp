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


// Bottom up aaproach  
   

class Solution {

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        if(n == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for(int i = 2; i<n; i++){
            
            int taking = nums[i]+dp[i-2];
            int notTaking = dp[i-1];

            dp[i] = max(taking , notTaking);
        }
        return dp[n-1];
    }
};