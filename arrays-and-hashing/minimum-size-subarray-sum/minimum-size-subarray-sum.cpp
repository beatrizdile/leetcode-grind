class Solution {
	public:
		int minSubArrayLen(int target, vector<int>& nums) {
			int left = 0, right = 0, sum = 0;
			int result = INT_MAX;
	
			while (left <= right && right < nums.size()) {
				sum += nums[right];
				while (sum >= target) {
					result = result < (right - left + 1) ? result : (right - left + 1);
					sum -= nums[left];
					left++;
				}
				right++;
			}
	
			return result == INT_MAX ? 0 : result;
		}
	};
	