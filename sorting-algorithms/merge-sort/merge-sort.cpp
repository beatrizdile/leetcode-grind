class Solution {
    public:
        void conquer(vector<int>& nums, int start, int end, int mid) {
            vector<int> leftSide(nums.begin() + start, nums.begin() + mid + 1);
            vector<int> rightSide(nums.begin() + mid + 1, nums.begin() + end + 1);
    
            int index = start;
            int left = 0;
            int right = 0;
    
            while (left < leftSide.size() && right < rightSide.size()) {
                if (left < leftSide.size() && leftSide[left] <= rightSide[right]) {
                    nums[index] = leftSide[left];
                    left++;
                }
                else if (right < rightSide.size() && rightSide[right] < leftSide[left]) {
                    nums[index] = rightSide[right];
                    right++;
                }
    
                index++;
            }
    
            while (left < leftSide.size()) {
                nums[index] = leftSide[left];
                left++;
                index++;
            }
    
            while (right < rightSide.size()) {
                nums[index] = rightSide[right];
                right++;
                index++;
            }
        }
    
        void divide(vector<int>& nums, int start, int end) {
            if ((end - start + 1) <= 1)
                return ;
            
            int mid = (start + end) / 2;
            divide(nums, start, mid);
            divide(nums, mid + 1, end);
            conquer(nums, start, end, mid);
        }
    
        vector<int> sortArray(vector<int>& nums) {
            divide(nums, 0, nums.size() - 1);
            return nums;
        }
    };
    