/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 class Solution {
    public:
        int guessNumber(int n) {
            long left = 1;
            long right = INT_MAX;
    
            while (left <= INT_MAX) {
                long mid = (right + left) / 2;
                if (guess(mid) == -1) {
                    right = mid - 1;
                }
                else if (guess(mid) == 1) {
                    left = mid + 1;
                }
                else
                    return mid;
            }
    
            return -1;
        }
    };
