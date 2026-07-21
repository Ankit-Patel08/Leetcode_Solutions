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




// BY the using the concept of next smaller and previous smaller element we can solve this problem in O(n) time complexity

class Solution {
    private:
    void NextSmallElement(vector<int> & arr, vector<int>&ans){
        int n = arr.size();
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while( !st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void previousSmallEqualElement(vector<int> & arr, vector<int>&ans){
        int n = arr.size();
        stack<int>st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top(); 
            st.push(i);
        }
    }

public:
    int sumSubarrayMins(vector<int>& arr) {

        const int MOD = 1e9+7;
        int n = arr.size();
        vector<int>rightNextSmall(n);
        vector<int>leftNextSmallEqual(n);  // this equal to avoid the duplicate when ele equal
        NextSmallElement(arr,rightNextSmall);
        previousSmallEqualElement(arr, leftNextSmallEqual);

        int total = 0;

        for(int i = 0; i<n; i++){
            int left = i - leftNextSmallEqual[i];
            int right = rightNextSmall[i] - i;
            total = (total + (left * right * 1ll*arr[i]) % MOD)%MOD;
        }
        return total;
    }
};
