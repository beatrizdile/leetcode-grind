#include <iostream>

class Solution {
    public:
        std::string mergeAlternately(std::string word1, std::string word2) {
        std::string result = "";
        int word1Size = word1.size();
        int word2Size = word2.size();
        int i = 0;
        int j = 0;

        while (i < word1Size || j < word2Size) {
            if (i < word1Size) {
                result.push_back(word1[i]);
                i++;
            }

            if (j < word2Size) {
                result.push_back(word2[j]);
                j++;
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;

    std::cout << solution.mergeAlternately("abc", "pqr") << std::endl;
}
