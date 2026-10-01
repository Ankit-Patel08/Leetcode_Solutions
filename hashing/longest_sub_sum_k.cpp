/*
link -> https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
*/



// For the positive numbers we can use the sliding window technique to find the longest subarray with sum k
 class Solution {
	public:
	int longestSubarray(vector<int>& arr, int k) {
		
		int n = arr.size();
		int longestSubArray = 0;
		int sum = 0;
		int count = 0;
		int left = 0;
		for (int right = 0; right < n; right++) {
			sum += arr[right];
			count++;
			while (sum > k) {
				sum -= arr[left];
				left++;
				count--;
			}
			if (sum == k) {
				longestSubArray = max(longestSubArray, count);
			}
		}
		return longestSubArray;
	}
};
