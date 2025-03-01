class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxStrSize = 0;
            unordered_set <char> hashSet;
            int left = 0;
    
            for (int right = 0; right < s.size(); right++) {
                while (hashSet.find(s[right]) != hashSet.end()) {
                    hashSet.erase(s[left]);
                    left++;
                }
                hashSet.insert(s[right]);
                maxStrSize = maxStrSize > (right - left + 1) ? maxStrSize : (right - left + 1);
            }
            
            return maxStrSize;
        }
    };
