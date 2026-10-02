// 3. Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;        // Edge case: empty string
        if (s.length() == 1) return 1;        // Edge case: single character string

        unordered_map<char, int> mp;         // Map to store the count of characters in the current window
        int low = 0;                       // Pointer to the start of the current window
        int ans = 0;                      // Variable to store the length of the longest substring found

        for (int high = 0; high < s.length(); high++) {
            mp[s[high]]++;

            // If duplicate exists, shrink the window
            while (mp.size() < high - low + 1) {         // If the size of the map is less than the size of the current window, it means there are duplicates
                mp[s[low]]--;                         // Decrease the count of the character at the low pointer
                if (mp[s[low]] == 0) {                      // If the count of the character becomes zero, remove it from the map
                    mp.erase(s[low]);
                }
                low++;
            }
            ans = max(ans, high - low + 1);               // Update the answer with the maximum length of the substring found so far
        }
        return ans;
    }
};




int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}





// Revise 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>unique;
        int left = 0;
        int longestSubsLength = 0;
        int right = 0;
        for(; right < s.length(); right++){
            
            if(!unique.count(s[right])){
                unique.insert(s[right]);
            }else{
                while(unique.count(s[right])){
                    unique.erase(s[left]);
                    left++;
                }
                unique.insert(s[right]);
            }
            longestSubsLength = max(longestSubsLength, (right-left+1));
        }
        return longestSubsLength;
    }
};



// clean code
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>unique;
        int left = 0;
        int longestSubsLength = 0;
        int right = 0;
        for(; right < s.length(); right++){
                while(unique.count(s[right])){
                    unique.erase(s[left]);
                    left++;
                }
                unique.insert(s[right]);
            longestSubsLength = max(longestSubsLength, (right-left+1));
        }
        return longestSubsLength;
    }
}; 