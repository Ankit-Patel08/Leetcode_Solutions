/*
link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/2193728107/
*/

// Recursion + Memoization

class Solution {
private:
    int maxbenefit(int idx, int buy, vector<int>& prices,vector<vector<vector<int>>>&dp, int remTransation) {
        if (idx == prices.size() || remTransation  == 0)
            return 0;

        if(dp[idx][buy][remTransation] != -1) return dp[idx][buy][remTransation];
        int profit = 0;
        if (buy) {
            profit = max(
                    (-prices[idx] + maxbenefit(idx + 1, 0, prices, dp,remTransation)),
                    (0 + maxbenefit(idx + 1, 1, prices,dp,remTransation))
                );
        } else {
            profit = max(
                (prices[idx] + maxbenefit(idx+1, 1, prices,dp, remTransation-1)), 
                (0 + maxbenefit(idx+1, 0, prices,dp,remTransation))
            );
        }
        return dp[idx][buy][remTransation] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
        return maxbenefit(0, 1, prices, dp,2);
    }
};



// Tabulation

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int remTransaction = 1; remTransaction <= 2; remTransaction++){
                    int profit = 0;
                    if(buy){
                        profit = max( (-prices[i] + dp[i+1][0][remTransaction]),
                                        (0 + dp[i+1][1][remTransaction])
                        );
                    }else{
                         profit = max( (prices[i] + dp[i+1][1][remTransaction-1]),
                                        (0 + dp[i+1][0][remTransaction])
                        );
                    }
                    dp[i][buy][remTransaction] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};


// Space Optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      vector<vector<int>>before(2,vector<int>(3,0));
      vector<vector<int>>curr(2,vector<int>(3,0));
        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int remTransaction = 1; remTransaction <= 2; remTransaction++){
                    int profit = 0;
                    if(buy){
                        profit = max( (-prices[i] + before[0][remTransaction]),
                                        (0 + before[1][remTransaction])
                        );
                    }else{
                         profit = max( (prices[i] + before[1][remTransaction-1]),
                                        (0 + before[0][remTransaction])
                        );
                    }
                    curr[buy][remTransaction] = profit;
                    before = curr;
                }
            }
        }
        return before[1][2];
    }
};