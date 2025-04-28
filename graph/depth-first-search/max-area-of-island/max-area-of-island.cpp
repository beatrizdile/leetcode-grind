class Solution {
    public:
        int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j) {
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || visited[i][j] == 1 || grid[i][j] == 0)
                return 0;
    
            visited[i][j] = 1;
            int count = 1;
    
            count += dfs(grid, visited, i + 1, j);
            count += dfs(grid, visited, i - 1, j);
            count += dfs(grid, visited, i, j + 1);
            count += dfs(grid, visited, i, j - 1);
    
            return count;
        }
    
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
            int maxArea = 0;
    
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] == 1) {
                        maxArea = max(maxArea, dfs(grid, visited, i, j));
                    }
                }
            }
    
            return maxArea;
        }
    };
    