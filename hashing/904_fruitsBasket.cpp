/*
link -> https://leetcode.com/problems/fruit-into-baskets/description/
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>currSize;
        int maxFruits = 0;
        int left = 0;
        for(int right = 0; right < n; right++){

            currSize[fruits[right]]++;

            while(currSize.size() > 2){
                currSize[fruits[left]]--;
                if(currSize[fruits[left]] == 0) currSize.erase(fruits[left]);
                left++;
            }
            int totalFruits = 0;
            for(const auto &x: currSize){
                totalFruits += x.second;
            }
            maxFruits = max(maxFruits, totalFruits);
        }
        return maxFruits;
    }
};