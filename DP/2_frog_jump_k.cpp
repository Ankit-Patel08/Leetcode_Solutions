/*
1. Problem Idea

We have n stones with different heights.

From stone i, the frog can jump to any of the previous k stones.

The cost of jumping from stone j to stone i is:

abs(heights[i] - heights[j])

We need to find the minimum total cost to reach the last stone.



2. First Think in Recursion

Suppose we are currently at index idx.

To reach idx, the frog could have come from:

idx - 1
idx - 2
idx - 3
...
idx - k

So we try every possible previous position.

For every possible jump:

total cost =
    cost to reach previous stone
    +
    cost of current jump

Therefore:

f(idx) = min(
    f(idx-1) + cost(idx-1 → idx),
    f(idx-2) + cost(idx-2 → idx),
    ...
    f(idx-k) + cost(idx-k → idx)
)


3. Base Case

If the frog is already at the first stone:

if(idx == 0)
    return 0;

There is no cost required to reach the first stone.


4. Identify the DP State

Ask:

What information is changing in the recursive call?

Only idx changes.

Therefore:

dp[idx] = minimum cost required to reach index idx

This is our DP state.



5. Why Memoization?

Without memoization, the same index can be calculated many times.

For example:

                 5
              /  |  \
             4   3   2
            / \ / \ / \
           3  2 2  1 ...

The same states like 3, 2, etc. can occur repeatedly.

So we store the answer:

if(dp[idx] != -1)
    return dp[idx];

If we have already calculated idx, we simply reuse it.


6. Complexity

For every index, we try at most k previous positions.

There are n states.

Therefore:

Time Complexity  : O(n * k)
Space Complexity : O(n) + O(n)for the recurcive call

The O(n) space consists of:

dp array      → O(n)
recursion     → O(n) worst case

So the total auxiliary space with this recursive memoization approach is O(n).

*/



// RECURSION + MEMOIZATION 
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int maxJump(vector<int>&heights, int idx, vector<int>&dp, int k){
        if(idx == 0) return 0;
        
        if(dp[idx] != -1) return dp[idx];

        int mini = INT_MAX;
        for(int i = idx-1; i >= idx-k; i--){
            if(i < 0) break;
            mini = min(mini, maxJump(heights, i, dp, k)+abs(heights[idx]- heights[i]));
        }
      return  dp[idx] = mini;
    }
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int>dp(n+1, -1);
        return maxJump(heights,n-1, dp, k);
    }
};



// TABULATION (BOTTOM UP)
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int>dp(n);

        dp[0] = 0;
        int mini = INT_MAX;
        for(int i = 1; i < n; i++){
            int mini = INT_MAX;
             for(int j = i-1; j >= max(0, i-k); j--){
                mini = min(mini, dp[j] + abs(heights[i]-heights[j]));
             }
             dp[i] = mini;
        }
        return dp[n-1];
    }
};





