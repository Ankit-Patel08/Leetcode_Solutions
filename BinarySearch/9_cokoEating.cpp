/*
link -> https://leetcode.com/problems/koko-eating-bananas/description/
*/

// my intuity(first solution which came in my mind)
class Solution {
    private:
    bool check(vector<int>&piles, int h, int mid){
        int count = 0;
        for(auto pile : piles){
            count = count + (pile+(mid-1))/mid;
            if(count > h ) return true;
        }
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());  // we can also do r = 1e9 because the max value of piles[i] is 1e9
                                                           // but we prefer to do this because it will reduce the search space and make the code more efficient
                                                        // ans it is prefered to reduce the search space as much as possible to make the code more efficient
        while(l <= r){
            int mid = l+(r-l)/2;
            if(check(piles, h, mid)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
};