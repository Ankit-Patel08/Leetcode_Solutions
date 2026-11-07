/*
link -> https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxbenefit = 0;
        int mini = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            maxbenefit = max(maxbenefit, prices[i]-mini);
            mini = min(mini, prices[i]);
        }
        return maxbenefit;
    }
};