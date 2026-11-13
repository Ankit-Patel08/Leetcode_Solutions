/*
link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

//  Recursion + Memoization
class Solution {
    private:
    int maxBenefit(vector<vector<vector<int>>>&dp, vector<int>&prices, int idx, int buy, int remTrans){
        if(idx == prices.size() || remTrans == 0) return 0;

        if(dp[idx][buy][remTrans] != -1) return dp[idx][buy][remTrans];

        int profit = 0;
        if(buy){
            profit = max(
                (-prices[idx] + maxBenefit(dp, prices, idx+1, 0, remTrans)),
                (0 +  maxBenefit(dp, prices, idx+1, 1, remTrans))
            );
        }else{
             profit = max(
                (prices[idx] + maxBenefit(dp, prices, idx+1, 1, remTrans-1)),
                (0 +  maxBenefit(dp, prices, idx+1, 0, remTrans))
            );
        }
        return dp[idx][buy][remTrans] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2, vector<int>(k+1, -1)));

        return maxBenefit(dp, prices, 0, 1, k);
    }
};



// Tabulation
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int remTrans = 1; remTrans <= k; remTrans++){
                    int profit = 0;
                    if(buy){
                        profit = max((-prices[i] + dp[i+1][0][remTrans]),
                                       (0 + dp[i+1][1][remTrans])
                        );
                    }else{
                        profit = max((prices[i] + dp[i+1][1][remTrans-1]),
                                       (0 + dp[i+1][0][remTrans])
                        );
                    }
                    dp[i][buy][remTrans] = profit;
                }
            }
        }

        return dp[0][1][k];
    }
};


// Space Optimization
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>prev(2,vector<int>(k+1, 0));
        vector<vector<int>>curr(2,vector<int>(k+1, 0));


        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int remTrans = 1; remTrans <= k; remTrans++){
                    int profit = 0;
                    if(buy){
                        profit = max((-prices[i] + prev[0][remTrans]),
                                       (0 + prev[1][remTrans])
                        );
                    }else{
                        profit = max((prices[i] + prev[1][remTrans-1]),
                                       (0 + prev[0][remTrans])
                        );
                    }
                    curr[buy][remTrans] = profit;
                }
            }
            prev = curr;
        }
        return prev[1][k];
    }
};