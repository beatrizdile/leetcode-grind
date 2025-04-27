class Solution {
    public:
    
        string longestPalindrome(string str) {
            int strCount = 0;
            string longestStr;
    
            for (int i = 0; i < str.size(); i++) {
                int left = i;
                int right = i;
                string palindrome;
    
                while (left >= 0 && right < str.size() && str[left] == str[right]) {
                    if (strCount < right - left + 1) {
                        palindrome = string(str.begin() + left, str.begin() + right + 1);
                        strCount = palindrome.size();
                        longestStr = palindrome;
                    }
                    left--;
                    right++;
                }
    
                left = i + 1;
                right = i;
                palindrome = "";
    
                while (left >= 0 && right < str.size() && str[left] == str[right]) {
                    if (strCount < right - left + 1) {
                        palindrome = string(str.begin() + left, str.begin() + right + 1);
                        strCount = palindrome.size();
                        longestStr = palindrome;
                    }
                    left--;
                    right++;
                }
            }
    
            return longestStr;
        }
    };
