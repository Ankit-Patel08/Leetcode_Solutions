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


// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2,0));
        for(int i = n-1; i>= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                }else{
                    profit = max(prices[i] + dp[i+2][1], dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};  

// Space Optimization
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int nextBuy = 0;
        int next2Buy = 0;
        int nextSell = 0;
        int currBuy = 0;
        int currSell = 0;
        for (int i = n - 1; i >= 0; i--) {
            currBuy = max(-prices[i] + nextSell, nextBuy);
            currSell = max(prices[i] + next2Buy, nextSell);

            next2Buy = nextBuy; // storing the 2 previous

            nextBuy = currBuy;
            nextSell = currSell;
        }
        return currBuy;
    }
};