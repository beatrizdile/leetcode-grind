class Solution {
    public:
        void backtracking(int n, int k, int start, vector<int>& combinations, vector<vector<int>>& result) {
            if (combinations.size() == k) {
                result.push_back(combinations);
                return;
            }
    
            for (int i = start; i <= n; i++) {
                combinations.push_back(i);
                backtracking(n, k, i + 1, combinations, result);
                combinations.pop_back();
            }
        }
    
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> result;
            vector<int> combinations;
            backtracking(n, k, 1, combinations, result);
    
            return result;
        }
    };
    