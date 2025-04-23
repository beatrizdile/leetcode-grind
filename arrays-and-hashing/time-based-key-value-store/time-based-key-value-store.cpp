class TimeMap {
    private:
        map<string, vector<pair<string, int>>> timeMap;
    
    public:
        TimeMap() {}
        
        void set(string key, string value, int timestamp) {
            if (timeMap.count(key) == 0)
                timeMap[key] = {{value, timestamp}};
            else
                timeMap[key].push_back({value, timestamp});
        }
        
        string get(string key, int timestamp) {
            string res = "";
            
            if (timeMap.count(key) != 0) {
                vector<pair<string, int>> timedValues = timeMap[key];
                int left = 0;
                int right = timedValues.size() - 1;
    
                while (left <= right) {
                    int mid = (left + right) / 2;
    
                    if (timedValues[mid].second <= timestamp) {
                        res = timedValues[mid].first;
                        left = mid + 1;
                    }
                    else if (timedValues[mid].second > timestamp)
                        right = mid - 1;
                }
    
            }
    
            return res;
        }
    };
    