class Solution {
    public:
        void bfs(vector<vector<char>>& grid, int row, int col) {
            queue<pair<int, int>> toVisit;
            grid[row][col] = '0';
            toVisit.push({row, col});
    
            while (!toVisit.empty()) {
                pair<int, int> pos = toVisit.front();
                toVisit.pop();
    
                int r = pos.first, c = pos.second;
                if (r + 1 < grid.size() && grid[r+1][c] == '1') {
                    toVisit.push({r+1, c});
                    grid[r+1][c] = '0';
                }
                if (r - 1 >= 0 && grid[r-1][c] == '1') {
                    toVisit.push({r-1, c});
                    grid[r-1][c] = '0';
                }
                if (c + 1 < grid[r].size() && grid[r][c+1] == '1') {
                    toVisit.push({r, c+1});
                    grid[r][c+1] = '0';
                }
                if (c - 1 >= 0 && grid[r][c-1] == '1') {
                    toVisit.push({r, c-1});
                    grid[r][c-1] = '0';
                }
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            int islands = 0;
    
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] == '1') {
                        bfs(grid, i, j);
                        islands++;
                    }                
                }
            }
    
            return islands;
        }
    };
    