class Solution {
    public:
        int bfs(vector<vector<int>>& grid, queue<pair<int, int>> rotten) {
            int time = 0;
    
            while (!rotten.empty()) {
                bool hasRotten = false;
                int size = rotten.size();
                for (int num = 0; num < size; num++) {
                    pair<int, int> pos = rotten.front();
                    rotten.pop();
    
                    vector<pair<int, int>> directions = {{-1, 0}, {0,-1}, {1,0}, {0,1}};
                    for (auto dir : directions) {
                        int i = pos.first + dir.first;
                        int j = pos.second + dir.second;
    
                        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 2 || grid[i][j] == 0)
                            continue ;
    
                        rotten.push({i, j});
                        grid[i][j] = 2;
                        hasRotten = true;
                    }
                }
                if (hasRotten) time++;
            }
    
            return time;
        }
    
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int, int>> rotten;
            bool existsFreshOrange = false;
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] == 2)
                        rotten.push({i, j});
                    if (grid[i][j] == 1)
                        existsFreshOrange = true;
                }
            }
    
            if (!existsFreshOrange)
                return 0;
            if (rotten.empty() && existsFreshOrange)
                return -1;
    
            int res = bfs(grid, rotten);
    
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] == 1)
                        return -1;
                }
            }
    
            return res;
        }
    };
