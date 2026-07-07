/*
link -> https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
    Floor in a Sorted Array

*/




class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int l = 0;
        int r = arr.size()-1;
        
            while(l <= r){
            int mid = l + (r-l)/2;
            
            if(x == arr[mid] && x == arr[mid+1]){
                l = mid+1;
            }else if(x == arr[mid]){
                return mid;
            }else if(x < arr[mid]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return r;
    }
};