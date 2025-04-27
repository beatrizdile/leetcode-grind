class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maxArea = min(height.front(), height.back()) * (height.size() - 1);
            int left = 0;
            int right = height.size() - 1;
    
            while (left < right) {
                int distance = right - left;
                int minHeight = (maxArea + distance - 1) / distance;
    
                if (height[left] < minHeight) {
                    left++;
                    continue ;
                }
                if (height[right] < minHeight) {
                    right--;
                    continue ;
                }
    
                maxArea = min(height[left], height[right]) * distance;
    
                if (height[left] < height[right])
                    left++;
                else
                    right--;
            }
    
            return maxArea;
        }
    };
    