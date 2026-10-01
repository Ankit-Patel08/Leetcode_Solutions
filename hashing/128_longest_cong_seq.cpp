/*
link -> https://leetcode.com/problems/longest-consecutive-sequence/description/
          Longest Consecutive Sequence (Leetcode Qno. -> 128)    
*/


// My intuitive approach is to use the map to store the frequency of the numbers and then check for the consecutive numbers and count them
// and return the maximum count of the consecutive numbers.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int>order;
        for(auto &x : nums){
            order[x]++;
        }
        if(order.size() == 0) return 0;
        if(order.size() == 1) return 1;
        int maxCount = 0;
        auto prev_key = order.begin();
        int currentCount = 1;

        auto it = order.begin();
        ++it;
        for(; it != order.end(); ++it){
            if(prev_key->first+1 == it->first){
                currentCount++;
            }else{
                maxCount = max(maxCount, currentCount);
                currentCount = 1;
            }
            prev_key = it;
        }
        return max(maxCount, currentCount);
    }
};