/*
link -> https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;
        int longestSubstring = 0;
        mp[0] = 0;
        int sum = 0;
        for(int right = 1; right <= n; right++){
            sum += arr[right-1];
            
            if(mp.count(sum)){
                longestSubstring = max(longestSubstring, (right-mp[sum]));
            }
            if(!mp.count(sum)){
                mp[sum] = right;
            }
        }
        return longestSubstring;
    }
};