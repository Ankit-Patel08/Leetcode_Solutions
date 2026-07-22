/*
link -> https://leetcode.com/problems/asteroid-collision/


 THIS IS THE MENTAL MODEL OF THE ASTEROID COLLISION PROBLEM

 Current asteroid arrives
        ↓
Fight with stack top
        ↓
Is current destroyed?
      /      \
    Yes       No
    |          |
Discard     Continue fighting
               |
        Survived everyone?
               |
             Push it

*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();
        for(int i = 0; i < n; i++){
          bool isSurvived = true;
         
         while( !st.empty() && st.top() > 0 && asteroids[i] < 0 ){

            if(st.top() < -asteroids[i]){
                st.pop();
            }
            else if(st.top() == -asteroids[i]){
                st.pop();
                isSurvived = false;
                break;
            }
            else{
                isSurvived = false;
                break;
            }
         }
         if(isSurvived){
            st.push(asteroids[i]);
         }
        }
        stack<int>stReverse;
        while(!st.empty()){
            stReverse.push(st.top());
            st.pop();
        }
        vector<int>ans;
        while(!stReverse.empty()){
            ans.push_back(stReverse.top());
            stReverse.pop();
        }
        return ans;
    }
};

