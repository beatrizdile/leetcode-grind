class Solution {
    private:
        vector<vector<int>> result;
    
    public:
        void getSubsets(vector<int>& current, vector<int>& nums, int i) {
            if (i >= nums.size()) {
                result.push_back(current);
                return ;
            }
            
            current.push_back(nums[i]);
            getSubsets(current, nums, i+1);
    
            current.pop_back();
            getSubsets(current, nums, i+1);
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> current;
            getSubsets(current, nums, 0);
    
            return result;
        }
    };
    