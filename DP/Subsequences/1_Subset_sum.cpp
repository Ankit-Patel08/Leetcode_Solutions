/*
link -> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

// Recursive C++ program to solve subset sum problem  (my intuitive approach)
class Solution {
    private:
     bool isthereSubset(vector<int>& arr, int sum, int idx){
          if(sum == 0) return true;
          if(sum < 0 || idx >= arr.size()) return false;
          
          if(isthereSubset(arr, sum-arr[idx], idx+1)) return true;
           
          
        
        return isthereSubset(arr,sum, idx+1);
      }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return isthereSubset(arr, sum, 0);
    }
};


// Dynamic Programming approach  memoization

class Solution {
    private:
     bool isthereSubset(vector<int>& arr, int sum, int idx, vector<vector<int>>&dp){
          if(sum == 0) return true;
          if(sum < 0 || idx >= arr.size()) return false;
          
          if(dp[idx][sum] != -1) return dp[idx][sum];
          
          bool take = isthereSubset(arr, sum-arr[idx], idx+1, dp);
          bool nottake = isthereSubset(arr, sum, idx+1, dp);
          
        
         return dp[idx][sum] = take || nottake;  // take if answer exists in any branch
      }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return isthereSubset(arr, sum, 0,dp);
    }
};


