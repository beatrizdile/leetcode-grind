class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int size = nums.size();
            for (int left = 0; left < size; left++) {
                for (int right = left + 1; right < min(size, left + k + 1); right++) {
                    if (nums[left] == nums[right])
                        return true;
                }
            }
    
            return false;
        }
    };
