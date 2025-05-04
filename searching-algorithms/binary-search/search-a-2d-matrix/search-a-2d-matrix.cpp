class Solution {
    public:
        bool binarySearch(vector<int>& arr, int target) {
            int left = 0;
            int right = arr.size() - 1;
    
            while (left <= right) {
                int mid = (right + left) / 2;
    
                if (arr[mid] > target) {
                    right = mid - 1;
                }
                else if (arr[mid] < target) {
                    left = mid + 1;
                }
                else if (arr[mid] == target)
                    return true;
            }
    
            return false;
        }
    
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int up = 0;
            int down = matrix.size() - 1;
            
            while (down >= up) {
                int mid = (down + up) / 2;
                if (matrix[mid].front() <= target && matrix[mid].back() >= target) {
                    return binarySearch(matrix[mid], target);
                }
                else if (matrix[mid].front() > target) {
                    down = mid - 1;
                }
                else if (matrix[mid].back() < target) {
                    up = mid + 1;
                }
            }
    
            return false;
        }
    };
    