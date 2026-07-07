/*
link ->  https://www.geeksforgeeks.org/problems/implement-lower-bound/1

Given a sorted array arr[] (following 0-based indexing) and a number target, find the lower bound of the 
target in this given array. The lower bound of a number is defined as the smallest index 
in the sorted array where the element is greater than or equal to the given number.

Note: If all the elements in the given array are smaller than the target, 
the lower bound will be the length of the array. 

*/

// all test cases passed on gfg it fails for the test case on leetcode so i have added the leetcode solution as well

  //     (If mid == 0, then arr[mid-1] becomes arr[-1], which is out of bounds and causes undefined behavior.) 
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int l = 0;
        int r = arr.size()-1;
        while( l <= r){
            int mid = l +(r-l)/2;
            
            if(target == arr[mid] && arr[mid-1] == target){
                r = mid-1;
            }else if(target == arr[mid]){
                return mid;
            }
            
           else if(target < arr[mid]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};


// for the leetcode 

class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        int ans = arr.size();

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};


