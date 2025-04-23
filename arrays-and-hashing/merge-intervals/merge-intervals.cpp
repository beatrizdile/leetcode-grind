class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
                    return a[0] < b[0];
            });
    
            vector<vector<int>> result;
            result.push_back({intervals[0][0], intervals[0][1]});
            for (int i = 0; i < intervals.size(); i++) {
                if (intervals[i][0] <= result[result.size() - 1][1])
                    result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);
                else
                    result.push_back({intervals[i][0], intervals[i][1]});
            }
    
            return result;
        }
    };
