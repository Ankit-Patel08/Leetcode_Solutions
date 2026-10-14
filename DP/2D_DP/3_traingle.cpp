/*
link -> https://leetcode.com/problems/triangle/description/
            Triangle (Leetcode Qno. -> 120)    
*/


class Solution {
private:
    int minSum(vector<vector<int>>& triangle, int m, vector<vector<int>>& dp,
               int row, int col, vector<vector<bool>>& visited) {
        if (row == m - 1)
            return triangle[m - 1][col];

        if (visited[row][col])
            return dp[row][col];

        visited[row][col] = true;
        int straightDown =
            triangle[row][col] + minSum(triangle, m, dp, row + 1, col,visited);

        int rightDown =
            triangle[row][col] + minSum(triangle, m, dp, row + 1, col + 1,visited);

        return dp[row][col] = min(straightDown, rightDown);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m, vector<int>(m, 0));
         vector<vector<bool>> visited(m, vector<bool>(m, false));

        return minSum(triangle, m, dp, 0, 0,visited);
    }
};