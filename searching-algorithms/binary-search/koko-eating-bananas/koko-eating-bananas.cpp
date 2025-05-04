class Solution {
    public:
        long calculateHoursToEatPile(vector<int>& piles, int bananaRate) {
            long long totalHours = 0;
            for (int i = 0; i < piles.size(); i++)
                totalHours += (piles[i] + bananaRate - 1LL) / bananaRate;
    
            return totalHours;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            long left = 1;
            long right = *max_element(piles.begin(), piles.end());
            long res = right;
    
            while (left <= right) {
                int mid = (right + left) / 2;
                long hoursToEatPile = calculateHoursToEatPile(piles, mid);
    
                if (hoursToEatPile <= h && res > mid) {
                    res = mid;
                }
                else if (hoursToEatPile > h) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
    
            return res;
        }
    };
