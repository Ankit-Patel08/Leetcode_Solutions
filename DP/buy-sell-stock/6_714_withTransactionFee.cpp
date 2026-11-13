/*
link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
*/

// Recursion + Memoization

class Solution {
private:
    int maxBenefits(vector<int>& prices, int fee, int idx, int buy, vector<vector<int>>&dp) {
        if (idx >= prices.size())
            return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[idx] + maxBenefits(prices, fee, idx + 1, 0,dp),
                        (0 + maxBenefits(prices, fee, idx + 1, 1,dp)));
        }else{
            profit = max((prices[idx]-fee)+maxBenefits(prices, fee, idx+1, 1,dp),
                        (0 + maxBenefits(prices, fee, idx+1, 0,dp))
            );
        }
        return dp[idx][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n  = prices.size();

        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return maxBenefits(prices,fee, 0, 1,dp);
    }
};