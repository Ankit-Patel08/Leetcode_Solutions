/*
link -> https://leetcode.com/problems/minimum-window-substring/
*/

class Solution {
private:
    bool isContains(unordered_map<char, int>& s, unordered_map<char, int>& t) {
        for (const auto& x : t) {
            auto it = s.find(x.first);
            if (it == s.end() || it->second < x.second)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (n > m)
            return "";

        unordered_map<char, int> tt;
        for (auto& x : t) {
            tt[x]++;
        }

        unordered_map<char, int> ss;
        int minLength = INT_MAX;
        int bestLeft = 0;
        int left = 0;
        for (int right = 0; right < m; right++) {
            ss[s[right]]++;
            while (isContains(ss, tt)) {
                int currLength = right-left+1;
                if (currLength < minLength) {
                    minLength = currLength;
                    bestLeft = left;
                }
                ss[s[left]]--;
                left++;
            }
        }
        if(minLength == INT_MAX) return "";
        return s.substr(bestLeft, minLength);
    }
};