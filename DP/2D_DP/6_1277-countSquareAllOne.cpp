/*
link -> https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/


// Recursive + Memoization

class Solution {
    private:
    int squareCount(vector<vector<int>>& matrix, int row, int col, int m, int n, vector<vector<int>>&dp){
        if(row >= m || col >= n) return 0;
        if(matrix[row][col] == 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        

        int right =  squareCount(matrix, row, col+1, m, n,dp);
        int diagonal =  squareCount(matrix, row+1, col+1, m, n,dp);
        int down =  squareCount(matrix, row+1, col, m, n,dp);

        return dp[row][col] = 1 + min({right, diagonal, down});
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    count += squareCount(matrix, i, j, m, n, dp);
                }
            }
        }
        return count;
    }
};
