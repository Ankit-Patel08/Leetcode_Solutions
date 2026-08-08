// link ->  https://leetcode.com/problems/hand-of-straights/description/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

         if(hand.size() % groupSize != 0) return false;

        map<int, int>Countmaping;

        for(auto x : hand){
            Countmaping[x]++;
        }
        
        for(auto &x : Countmaping){
            int num = x.first;
            int count = x.second;
            
            if(count == 0) continue;

            for(int i = 0; i < groupSize; i++){
                int currentNum = num+i;
                if(Countmaping[currentNum] < count){
                    return false;
                }
                Countmaping[currentNum] -= count;
            }
        }
        return true;
    }
};