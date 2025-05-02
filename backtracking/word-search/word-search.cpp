class Solution {
    public:
        bool dfs(vector<vector<char>>& board, int index, string word, map<pair<int, int>, bool>& visited, pair<int, int> pos) {
            if (pos.first >= board.size() || pos.second >= board[pos.first].size() || pos.first < 0 || pos.second < 0 || visited.count(pos) != 0 || board[pos.first][pos.second] != word[index])
                return false;
            
            if (index == word.size() - 1)
                return true;
            
            visited.insert({pos, true});
            bool result = dfs(board, index + 1, word, visited, {pos.first + 1, pos.second}) ||
                          dfs(board, index + 1, word, visited, {pos.first - 1, pos.second}) ||
                          dfs(board, index + 1, word, visited, {pos.first, pos.second + 1}) ||
                          dfs(board, index + 1, word, visited, {pos.first, pos.second - 1});
            visited.erase(pos);
    
            return result;
        }
    
        bool exist(vector<vector<char>>& board, string word) {
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    map<pair<int, int>, bool> visited;
                    if (dfs(board, 0, word, visited, {i, j}))
                        return true;
                }
            }
    
            return false;
        }
    };
    