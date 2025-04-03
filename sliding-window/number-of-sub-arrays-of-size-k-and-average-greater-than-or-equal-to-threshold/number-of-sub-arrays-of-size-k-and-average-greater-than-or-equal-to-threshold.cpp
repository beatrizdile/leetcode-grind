class Solution {
    public:
        int numOfSubarrays(vector<int>& arr, int k, int threshold) {
            int sum = 0;
            int count = 0;
            int left = 0;
    
            for (int right = 0; right < arr.size(); right++) {
                if (right - left >= k) {
                    sum = sum - arr[left];
                    left++;
                }
    
                sum = sum + arr[right];
    
                if ((sum / k) >= threshold && right - left + 1 == k)
                    count++;
            }
    
            return count;
        }
    };
