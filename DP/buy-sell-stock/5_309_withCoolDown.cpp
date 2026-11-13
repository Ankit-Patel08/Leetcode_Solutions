/*
link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/

// Recursion + Memoization

class Solution {
    private:
    int maxbenefit(int idx, int buy, vector<int>& prices,vector<vector<int>>&dp) {
        if (idx >= prices.size())
            return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if (buy) {
            profit = max(
                    (-prices[idx] + maxbenefit(idx + 1, 0, prices, dp)),
                    (0 + maxbenefit(idx + 1, 1, prices,dp))
                );
        } else {
            profit = max(
                (prices[idx] + maxbenefit(idx+2, 1, prices,dp)), 
                (0 + maxbenefit(idx+1, 0, prices,dp))
            );
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        return maxbenefit(0, 1, prices, dp);
    }
};