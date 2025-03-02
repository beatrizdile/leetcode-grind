class Solution {
    public:
        string longestPalindrome(string str) {
            string longest;
    
            for (int i = 0; i < str.size(); i++) {
                // odd
                int left = i, right = i;
                while (left >= 0 && right < str.size() && str[left] == str[right]) {
                    if (longest.size() < (right - left + 1))
                        longest = str.substr(left, (right - left + 1));
                    left--;
                    right++;
                }
    
                // even
                left = i;
                right = i+1;
                while (left >= 0 && right < str.size() && str[left] == str[right]) {
                    if (longest.size() < (right - left + 1))
                        longest = str.substr(left, (right - left + 1));
                    left--;
                    right++;
                }
            }
    
            return longest;
        }
    };
    