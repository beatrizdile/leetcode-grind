class Solution {
    public:
        int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
            int row = grid.size();
            int col = grid[0].size();
    
            if (i >= row || i < 0 || j >= col || j < 0 || grid[i][j] == 1 || visited[i][j] == 1)
                return 0;
            
            if (i == row - 1 && j == col - 1)
                return 1;
    
            visited[i][j] = 1;
            int count = 0;
    
            count += dfs(grid, visited, i + 1, j);
            count += dfs(grid, visited, i - 1, j);
            count += dfs(grid, visited, i, j + 1);
            count += dfs(grid, visited, i, j - 1);
            
            visited[i][j] = 0;
    
            return count;
        }
    
        int countPaths(vector<vector<int>>& grid) {
            vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
            return dfs(grid, visited, 0, 0);
        }
    };
    