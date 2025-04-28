class Solution {
    public:
        int bfs(vector<vector<int>>& grid, pair<int, int> coord) {
            vector<vector<int>> visited(grid.size(), vector<int>(grid[coord.first].size(), 0));
            queue<pair<int, int>> q;
            visited[coord.first][coord.second] = 1;
            q.push(coord);
            int count = 0;
    
            while (!q.empty()) {
                int size = q.size();
                for (int num = 0; num < size; num++) {
                    pair<int, int> pos = q.front();
                    q.pop();
                    
                    if (pos.first == grid.size() - 1 && pos.second == grid[pos.first].size() - 1)
                        return count;
    
                    if (!(pos.first + 1 < 0 || pos.first + 1 >= grid.size() || pos.second < 0 || pos.second >= grid[pos.first + 1].size() || grid[pos.first + 1][pos.second] == 1 || visited[pos.first + 1][pos.second] == 1)) {
                        q.push({pos.first + 1, pos.second});
                        visited[pos.first + 1][pos.second] = 1;
                    }
                    if (!(pos.first - 1 < 0 || pos.first - 1 >= grid.size() || pos.second < 0 || pos.second >= grid[pos.first - 1].size() || grid[pos.first - 1][pos.second] == 1 || visited[pos.first - 1][pos.second] == 1)) {
                        q.push({pos.first - 1, pos.second});
                        visited[pos.first - 1][pos.second] = 1;
                    }
                    if (!(pos.first < 0 || pos.first >= grid.size() || pos.second + 1 < 0 || pos.second + 1 >= grid[pos.first].size() || grid[pos.first][pos.second + 1] == 1 || visited[pos.first][pos.second + 1] == 1)) {
                        q.push({pos.first, pos.second + 1});
                        visited[pos.first][pos.second + 1] = 1;
                    }
                    if (!(pos.first < 0 || pos.first >= grid.size() || pos.second - 1 < 0 || pos.second - 1 >= grid[pos.first].size() || grid[pos.first][pos.second - 1] == 1 || visited[pos.first][pos.second - 1] == 1)) {
                        q.push({pos.first, pos.second - 1});
                        visited[pos.first][pos.second - 1] = 1;
                    }
                }
                count++;
            }
    
            return -1;
        }
    
        int shortestPath(vector<vector<int>>& grid) {
            return bfs(grid, {0, 0});
        }
    };
    