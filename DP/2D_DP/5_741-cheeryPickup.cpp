/*
link -> https://leetcode.com/problems/cherry-pickup/description/
            Cherry Pickup (Leetcode Qno. -> 741)
*/

// FROM 4D DP

class Solution {
private:
    int maxLength(vector<vector<vector<vector<int>>>>& dp, int r1, int c1,
                  int r2, int c2, int n, vector<vector<int>>& grid) {
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 ||
            grid[r2][c2] == -1)
            return INT_MIN;
        if ((r1 == n - 1 && c1 == n - 1) && (r2 == n - 1 && c2 == n - 1))
            return grid[r1][c1];

        if (dp[r1][c1][r2][c2] != -1)
            return dp[r1][c1][r2][c2];

        int cherries = 0;

        if (r1 == r2 && c1 == c2) {
            cherries += grid[r1][c1];
        } else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int f1 = maxLength(dp, r1, c1 + 1, r2, c2 + 1, n, grid);
        int f2 = maxLength(dp, r1 + 1, c1, r2, c2 + 1, n, grid);
        int f3 = maxLength(dp, r1, c1 + 1, r2 + 1, c2, n, grid);
        int f4 = maxLength(dp, r1 + 1, c1, r2 + 1, c2, n, grid);

        int best = max({f1, f2, f3, f4});

        if (best == INT_MIN) {
            return dp[r1][c1][r2][c2] = INT_MIN;
        }
        cherries += best;
        return dp[r1][c1][r2][c2] = cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<vector<int>>>> dp( // a 4D vector DP
            n, vector<vector<vector<int>>>(
                   n, vector<vector<int>>(n, vector<int>(n, -1))));

        int ans =  maxLength(dp, 0, 0, 0, 0, n, grid);

        return max(0, ans);
    }
};



// converted into 3D DP

class Solution {
private:
    int maxLength(vector<vector<vector<int>>>& dp, int r1, int c1,
                  int r2, int n, vector<vector<int>>& grid) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 ||
            grid[r2][c2] == -1)
            return INT_MIN;
        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = 0;

        if (r1 == r2 && c1 == c2) {
            cherries += grid[r1][c1];
        } else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int f1 = maxLength(dp, r1, c1 + 1, r2, n, grid);
        int f2 = maxLength(dp, r1 + 1, c1, r2, n, grid);
        int f3 = maxLength(dp, r1, c1 + 1, r2 + 1, n, grid);
        int f4 = maxLength(dp, r1 + 1, c1, r2 + 1, n, grid);

        int best = max({f1, f2, f3, f4});

        if (best == INT_MIN) {
            return dp[r1][c1][r2] = INT_MIN;
        }
        cherries += best;
        return dp[r1][c1][r2] = cherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, -1)));

        int ans = maxLength(dp, 0, 0, 0, n, grid);

        return max(0, ans);
    }
};