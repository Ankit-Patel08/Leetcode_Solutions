/*
link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/


// Recursive for to know all the possible ways to buy and sell stock
class Solution {
private:
    int maxbenefit(int idx, bool buy, vector<int>& prices, vector<vector<int>>&dp) {
        if (idx == prices.size())
            return 0;

            if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        if (buy) {
            profit = max(
                    (-prices[idx] + maxbenefit(idx + 1, false, prices, dp)),
                    (0 + maxbenefit(idx + 1, true, prices, dp))
                );
        } else {
            profit = max(
                (prices[idx] + maxbenefit(idx+1, true, prices, dp)), 
                (0 + maxbenefit(idx+1, false, prices, dp))
            );
        }
         return dp[idx][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return maxbenefit(0, true, prices);
    }
};


