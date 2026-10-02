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



// But if the -ve numbers are also present then we will go from prefix sum and hashing technique to find the longest subarray with sum k
class Solution {
	public:
	int longestSubarray(vector<int>& arr, int k) {
		
		int n = arr.size();
		int longestSubArray = 0;
		unordered_map<int ,int>mp;
		mp[0] = 0;
	    int sum = 0;
		for (int right = 1; right <= n; right++) {
			sum += arr[right-1];
			
			int need = sum - k;
			if(mp.count(need)){
			    longestSubArray = max(longestSubArray, (right-mp[need]));
			}
			
			if(!mp.count(sum)){
			    mp[sum] = right;
			}
		}
		return longestSubArray;
	}
};

