class Solution {
    private:
        vector<vector<int>> result;
    public:
        void getCombinations(vector<int>& candidates, vector<int> current, int currentSum, int target, int i) {        
            if (currentSum == target) {
                result.push_back(current);
                return ;
            }
    
            if (i >= candidates.size() || currentSum > target)
                return ;
    
            current.push_back(candidates[i]);
            getCombinations(candidates, current, currentSum + candidates[i], target, i);
    
            current.pop_back();
            getCombinations(candidates, current, currentSum, target, i + 1);
        }
    
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> current;
            getCombinations(candidates, current, 0, target, 0);
            return result;
        }
    };
