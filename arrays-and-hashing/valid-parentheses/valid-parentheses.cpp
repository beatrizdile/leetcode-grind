class Solution {
    public:
        bool isValid(string str) {
            stack<char> brackets;
            unordered_map<char, char> closeToOpen = {
                {']', '['},
                {'}', '{'},
                {')', '('},
            };
    
            for (auto ch : str) {
                if (!brackets.empty() && closeToOpen.count(ch) == 1) {
                    if (brackets.top() == closeToOpen[ch])
                        brackets.pop();
                    else
                        return false;
                }
                else
                    brackets.push(ch);
            }
    
            return brackets.empty();
        }
    };
    