class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> anagrams;
    
            for (int i = 0; i < strs.size(); i++) {
                string anagramKey = strs[i];
                sort(anagramKey.begin(), anagramKey.end());
                anagrams[anagramKey].push_back(strs[i]);
            }
    
            vector<vector<string>> result;
            for (auto anagram : anagrams) {
                result.push_back(anagram.second);
            }
    
            return result;
        }
    };
    