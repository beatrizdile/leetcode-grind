class Solution {
    public:
        bool bfs(vector<vector<int>>& heights, pair<int, int> coord) {
            vector<vector<int>> visited(heights.size(), vector<int>(heights[coord.first].size(), 0));
            queue<pair<int, int>> toVisit;
            bool pacific = false;
            bool atlantic = false;
    
            toVisit.push(coord);
    
            while (!toVisit.empty()) {
                pair<int, int> pos = toVisit.front();
                toVisit.pop();
                visited[pos.first][pos.second] = 1;
    
                vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
                for (auto direction : directions) {
                    int i = pos.first + direction.first;
                    int j = pos.second + direction.second;
    
                    if (i < 0 || j < 0 || i >= heights.size() || j >= heights[i].size()) {
                        if (i < 0 || j < 0)
                            pacific = true;
                        else
                            atlantic = true;
                        continue;
                    }
                    if (heights[i][j] <= heights[pos.first][pos.second] && visited[i][j] == 0)
                        toVisit.push({i, j});
                }
            }
    
            return pacific && atlantic;
        }
    
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            vector<vector<int>> result;
            for (int i = 0; i < heights.size(); i++) {
                for (int j = 0; j < heights[i].size(); j++) {
                    if (bfs(heights, {i, j}))
                        result.push_back({i, j});
                }
            }
    
            return result;
        }
    };
