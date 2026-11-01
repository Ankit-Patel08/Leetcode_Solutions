/*
link -> https://leetcode.com/problems/01-matrix/description/
*/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>mat1 = mat;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        //           OR 
        // bool visited[m][n] = {false};
        vector<vector<int>>ans(m, vector<int>(n, -1));
        queue<pair<int,int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        int count = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty()){
            int sz = q.size();
            count++;
            for(int i = 1; i <= sz; i++){
                int x = q.front().first;
                int y = q.front().second;
                for(int j = 0; j < 4; j++){
                    int newX = x+dx[j];
                    int newY = y+dy[j];
                    if(newX >= 0 && newY >= 0 && newX < m && newY < n && ans[newX][newY] == -1){
                        ans[newX][newY] = count;
                        q.push({newX, newY});
                    }
                }
                q.pop();
            }
        }
        return ans;
    }
};