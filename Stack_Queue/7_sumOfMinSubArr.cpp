/*
link ->  https://leetcode.com/problems/sum-of-subarray-minimums/
*/



// o(n^2) solution
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9+7;
        int ans = 0;
        for(int i = 0; i<n; i++){
            int mini = INT_MAX;
            for(int j = i; j<n; j++){
                mini = min(mini, arr[j]);
                ans = (ans+mini) % MOD;
            }
        }
        return ans % MOD;
    }
};



