/*
link -> https://leetcode.com/problems/unique-paths/description/
          Unique Paths (Leetcode Qno. -> 62)    
*/


#include<bits/stdc++.h>
using namespace std;


//  Recursive way to solve this
int Recursive_ways(int row, int col){
    if(row == 0 && col == 0) return 1;

    if(row< 0 || col < 0) return 0;

    int up = Recursive_ways(row-1, col);
    int left = Recursive_ways(row, col-1);

    return up+left;
}


// TIME COMPLEXITY
/*
Now this gives the time complexity of the 2^(m+n)

TIME COMPLEXITY   ->    Time≈(choices per step)^(maximum depth)​

here at every points we have 2 choices and maximum path it can travel is m+n 

so the same time complexity can become 4^(m*n)  if we are allowed to move in all the 4 directions
  because the max path we can move is m*n (and that is also due to the allowence of the movement in 4 directions)
*/



// OPTIMISED SOLUTION 
/*
Here we are getting the very high TC so we have to look for the better solution 

  After observation we can see the many overlapping problem so we can think of to store the calculated vlaue 
   so what this current ROW and COLS saying " the number of ways to reach at row and col if we start from the (0,0)"
      so we can use this information to store the value so to reduce the TC 
      and this concept is knows as the DP 
*/

int Top_down_ways(int row, int col, vector<vector<int>>&dp){
    if(row == 0 && col == 0) return 1;

    if(row <0 || col<0) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    return dp[row][col] = Top_down_ways(row-1, col,dp) + Top_down_ways(row, col-1, dp);
}





int main(){
    int rows, cols;
    cin>>rows>>cols;

    vector<vector<int>>dp(rows, vector<int>(cols,-1));

    cout<<Recursive_ways(rows-1, cols-1);

    cout<<Top_down_ways(rows-1, cols-1, dp);

}