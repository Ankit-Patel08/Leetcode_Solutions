/*
link -> https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

// Recursive C++ program to solve subset sum problem  (my intuitive approach)
class Solution {
    private:
     bool isthereSubset(vector<int>& arr, int sum, int idx){
          if(idx <= arr.size() && sum == 0) return true;
          if(sum < 0 || idx >= arr.size()) return false;
          
          if(isthereSubset(arr, sum-arr[idx], idx+1)) return true;
          if(isthereSubset(arr,sum, idx+1)) return true;
          
          return false;
      }
    
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return isthereSubset(arr, sum, 0);
    }
};