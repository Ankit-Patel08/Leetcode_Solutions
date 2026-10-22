/*
link -> https://www.geeksforgeeks.org/problems/aggressive-cows/
*/


class Solution {
    private:
     bool isPoss(vector<int>&arr, int minDist, int k){
        int count = 1;
        int lastPos = arr[0];
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - lastPos >= minDist){
                count++;
                lastPos = arr[i];
                if(count >= k) return true;
            }
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        int low = 0;         // minimum distance between two aggresive can be 0
        sort(arr.begin(), arr.end());
        int high = arr[n-1]-arr[0];    // maximum distance between two aggresive can be max-min of the array
        int ans = 0;
        while(low <= high){
            int mid = low+(high-low)/2;
            
            if(isPoss(arr, mid, k)){
                ans = mid;                     // storing the current mid as answer
                low = mid+1;                   // now we are trying to making the gap between the aggresive cows more bigger so that we can maximize the minimum distance between them
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};