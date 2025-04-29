class Solution {
    public:
        int result = 0;
        int target;
    
        void findValidSteps(int i) {
            if (i == target) {
                result++;
                return ;
            }
    
            if (i > target)
                return ;
            
            findValidSteps(i + 1);
            findValidSteps(i + 2);
        }
    
        int climbStairs(int n) {
            target = n;
            findValidSteps(0);
            return result;
        }
    };
    
    // 1
        // 1 + 1 = 2
            // 2 + 1 = 3 | FOUND
            // 2 + 2 = 3 | INVALID
        // 1 + 2 = 3 | FOUND
    
    // 2
        // 2 + 1 = 3 | FOUND
        // 2 + 2 = 4 | INVALID
    
    // res = 3
    