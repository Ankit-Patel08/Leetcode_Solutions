/*
link ->https://leetcode.com/problems/unique-paths-ii/description/  
          Unique Paths II (Leetcode Qno. -> 63)    
*/

class Solution {
    private:
    int ways(vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp, int currRow, int currCol){
        if(currRow == 0 && currCol == 0) return 1;
        if(currRow < 0 || currCol < 0 || obstacleGrid[currRow][currCol] == 1) return 0;

        if(dp[currRow][currCol] != -1) return dp[currRow][currCol];
        
       int up = ways(obstacleGrid, dp, currRow-1, currCol);
       int left = ways(obstacleGrid, dp, currRow, currCol-1);

       return dp[currRow][currCol] = up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>>dp(m, vector<int>(n,-1));

        return ways(obstacleGrid, dp, m-1, n-1);
    }
};