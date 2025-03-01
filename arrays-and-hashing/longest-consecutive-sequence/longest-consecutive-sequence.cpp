class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set <int> hashSet(nums.begin(), nums.end());
    
            int maxLength = 0;
            for (int num : hashSet) {
                if (hashSet.find(num - 1) == hashSet.end()) {
                    int length = 1;
                    while (hashSet.find(num + length) != hashSet.end()) {
                        length++;
                    }
                    maxLength = max(maxLength, length);
                }
            }
    
            return maxLength;
        }
    };
    