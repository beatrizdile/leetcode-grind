class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::map<int, int> numsHash;
    
            for (auto it = nums.begin(); it != nums.end(); it++) {
                numsHash[*it] = distance(nums.begin(), it);
            }
    
            for (int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i];
                if (numsHash.find(complement) != numsHash.end() && numsHash[complement] != i)
                    return {numsHash[complement], i};
            }
    
            return {};
        }
    };
