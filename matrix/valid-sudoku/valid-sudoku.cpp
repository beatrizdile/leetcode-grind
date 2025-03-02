class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            map<pair<int, int>, unordered_set <char>> squares;
            map<int, unordered_set <char>> rows, columns;
    
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board.size(); j++) {
                    if (board[i][j] == '.')
                        continue;
    
                    pair<int, int> key = {i / 3, j / 3};
    
                    if (columns[i].find(board[i][j]) != columns[i].end()
                        || rows[j].find(board[i][j]) != rows[j].end()
                        || squares[key].find(board[i][j]) != squares[key].end()) {
                            return false;
                        }
                    
                    columns[i].insert(board[i][j]);
                    rows[j].insert(board[i][j]);
                    squares[key].insert(board[i][j]);
                }
            }
    
            return true;
        }
    };
