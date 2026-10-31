/*
link -> https://leetcode.com/problems/rotting-oranges/description/
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        int minutes = 0;
        while(!q.empty()){
            int sz = q.size();
            int rotten = false;
            for(int i = 1; i <= sz; i++){
                 int x = q.front().first;
                 int y = q.front().second;
                for(int j = 0; j < 4; j++){
                    int newX = x+dx[j];
                    int newY = y+dy[j];
                    if(newX >= 0 && newY >= 0 && newX < m && newY < n && grid[newX][newY] == 1){
                        q.push({newX,newY});
                        grid[newX][newY] = 2;
                        rotten = true;
                    }
                }
                q.pop();
            }
            if(rotten) minutes++;
        }
         for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return minutes;
    }
};