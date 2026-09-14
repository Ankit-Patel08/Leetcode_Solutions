/*
link -> https://leetcode.com/problems/unique-paths/description/
          Unique Paths (Leetcode Qno. -> 62)    
*/


#include<bits/stdc++.h>
using namespace std;


//  Recursive way to solve this
int ways(int row, int col){
    if(row == 0 && col == 0) return 1;

    if(row< 0 || col < 0) return 0;

    int up = ways(row-1, col);
    int left = ways(row, col-1);

    return up+left;
}

int main(){
    int rows, cols;
    cin>>rows>>cols;

    cout<<ways(rows-1, cols-1);

}