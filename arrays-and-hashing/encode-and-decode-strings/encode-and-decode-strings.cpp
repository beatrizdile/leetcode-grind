class Solution {
    public:
    
        string encode(vector<string>& strs) {
            string result;
            for (auto word : strs) {
                result += to_string(word.size()) + '#' + word;
            }
    
            return result;
        }
    
        vector<string> decode(string s) {
            vector<string> result;
            int i = 0;
            while (i < s.size()) {
                int j = i;
                while (s[j] != '#')
                    j++;
                
                int length = stoi(s.substr(i, j-i + 1));
                string word = s.substr(j+1, length);
                result.push_back(word);
                i = j + length + 1;
            }
    
            return result;
        }
    };
    