 /*
 link -> https://www.geeksforgeeks.org/problems/implement-upper-bound/1
 
 */
 
 class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
         int l = 0;
         int r = arr.size()-1;
         while(l <= r){
             int mid = l+(r-l)/2;
             
             if(target == arr[mid] && target == arr[mid+1]){
                 l = mid+1;
             }else if(target < arr[mid]){
                 r = mid-1;
             }else{
                 l = mid+1;
             }
         }
         return l;
    }
};
