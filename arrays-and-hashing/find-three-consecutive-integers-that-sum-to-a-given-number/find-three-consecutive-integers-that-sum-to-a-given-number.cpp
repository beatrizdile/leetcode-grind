class Solution {
    public:
        vector<long long> sumOfThree(long long num) {
            vector<long long> result;
    
            long long middle = num/3 - 1;
            for (int i = 0; i < 3; i++) {
                result.push_back(middle + i);
            }
    
            long long sum = 0;
            for (auto num : result)
                sum += num;
    
            if (num != sum)
                return {};
    
            return result;
        }
    };
    