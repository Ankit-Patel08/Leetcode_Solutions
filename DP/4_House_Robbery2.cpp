/*
link ->   https://leetcode.com/problems/house-robber-ii/description/
          House Robber 2 (Leetcode Qno. -> 213)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int maxRob(vector<int>&nums){
        int n = nums.size();
        int taking = nums[0];
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int notTaking = max(nums[1], nums[0]);

        for(int i = 2; i<n; i++){
            int curr = max(nums[i]+taking, notTaking);
            
            taking = notTaking;
            notTaking = curr;
        }
        return notTaking;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int>firstElementInclude;
        for(int i = 0; i<n-1; i++){
            firstElementInclude.push_back(nums[i]);
        }

        vector<int>firstElementNotInclude;
         for(int i = 1; i<n; i++){
            firstElementNotInclude.push_back(nums[i]);
        }

        int takingFirstElement = maxRob(firstElementInclude);
        int notTakingFirstElement  = maxRob(firstElementNotInclude);

        return max(takingFirstElement, notTakingFirstElement);
    }
};