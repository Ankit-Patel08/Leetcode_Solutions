/*
link -> https://leetcode.com/problems/unique-paths/description/
          Unique Paths (Leetcode Qno. -> 62)    
*/


#include<bits/stdc++.h>
using namespace std;


//  Recursive way to solve this
int Recursive_ways(int row, int col){
    if(row == 0 && col == 0) return 1;

    if(row< 0 || col < 0) return 0;

    int up = Recursive_ways(row-1, col);
    int left = Recursive_ways(row, col-1);

    return up+left;
}


/*
Now this gives the time complexity of the 2^(m+n)

TIME COMPLEXITY   ->    Time≈(choices per step)^(maximum depth)​

here at every points we have 2 choices and maximum path it can travel is m+n 

so the same time complexity can become 4^(m*n)  if we are allowed to move in all the 4 directions
  because the max path we can move is m*n (and that is also due to the allowence of the movement in 4 directions)
*/


int main(){
    int rows, cols;
    cin>>rows>>cols;

    cout<<Recursive_ways(rows-1, cols-1);

}