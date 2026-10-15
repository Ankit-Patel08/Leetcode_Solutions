/*
link -> https://leetcode.com/problems/minimum-falling-path-sum/description/
            Minimum Falling Path Sum (Leetcode Qno. -> 931)    
*/

class Solution {
    private:
    int minSum(vector<vector<int>>& matrix, int row, int col, vector<vector<bool>>&visited, vector<vector<int>>&dp, int n){
        if(row < 0 || col < 0 || col >= n) return INT_MAX;
        if(row == n-1) return matrix[row][col];

        if(visited[row][col]) return dp[row][col];

        visited[row][col] = true;

        int belowLeft = minSum(matrix, row+1, col-1,visited,dp,n);
        int below  = minSum(matrix, row+1, col,visited,dp,n);
        int belowRight = minSum(matrix, row+1, col+1,visited,dp,n);

        return dp[row][col] = matrix[row][col] +  min({belowLeft,below, belowRight});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        vector<vector<bool>>visited(n, vector<bool>(n,false));
        vector<int>ans(n);

        for(int i = 0; i<n; i++){
            ans[i] = minSum(matrix,0,i,visited,dp,n);
        }
        return *min_element(ans.begin(), ans.end());
    }
};