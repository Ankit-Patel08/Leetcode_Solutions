/*
link ->https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
*/

class Solution {
	private:
	void dfs(vector<vector<char>> &grid, int Orow, int Ocol, int Nrow, int Ncol, vector<vector<bool>> &visited, vector<pair<int, int>> &island,int m, int n) {
		visited[Nrow][Ncol] = true;
		island.push_back({(Nrow-Orow),(Ncol-Ocol)});
		int dx[] = {1, 0, -1, 0};
		int dy[] = {0, 1, 0, -1};
		
		for (int i = 0; i < 4; i++) {
			int newX = Nrow + dx[i];
			int newY = Ncol + dy[i];
			if(newX >= 0 && newY >= 0 && newX < m && newY < n &&grid[newX][newY] == 'L' && !visited[newX][newY]){
			    dfs(grid, Orow, Ocol, newX, newY,visited, island,m,n);
			}
		}
	}
	public:
	int countDistinctIslands(vector<vector<char>> & grid) {
		// code here
		int m = grid.size();
		int n = grid[0].size();
		set<vector<pair<int, int>> >uniqueIslands;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		
		for (int i = 0; i <m; i++) {
			for (int j = 0; j <n; j++) {
				if (grid[i][j] == 'L' && !visited[i][j]) {
					vector<pair<int, int>> island;
					dfs(grid, i, j,i,j, visited, island,m,n);
					uniqueIslands.insert(island);
				}
			}
		}
		return uniqueIslands.size();
	}
};
