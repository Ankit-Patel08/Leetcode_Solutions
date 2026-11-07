/*
link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/


// Recursive for to know all the possible ways to buy and sell stock
class Solution {
private:
    int maxbenefit(int idx, bool buy, vector<int>& prices) {
        if (idx == prices.size())
            return 0;

        int profit = 0;
        if (buy) {
            profit = max(
                    (-prices[idx] + maxbenefit(idx + 1, false, prices)),
                    (0 + maxbenefit(idx + 1, true, prices))
                );
        } else {
            profit = max(
                (prices[idx] + maxbenefit(idx+1, true, prices)), 
                (0 + maxbenefit(idx+1, false, prices))
            );
        }
        return profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        return maxbenefit(0, true, prices);
    }
};