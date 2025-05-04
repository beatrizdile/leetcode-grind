// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    public:
        int firstBadVersion(int n) {
            long left = 1;
            long right = n;
    
            while (left <= right) {
                int mid = (left + right) / 2;
                if (isBadVersion(mid) && (mid == 1 || !isBadVersion(mid - 1))) {
                    return mid;
                }
                else if (isBadVersion(mid)) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
    
            return -1;
        }
    };
