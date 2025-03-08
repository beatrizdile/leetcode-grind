class Solution {
	public:
		int characterReplacement(string str, int k) {
			unordered_map<char, int> charsFreq;
			int result = 0;
			int left = 0;
	
			for (int right = 0; right < str.size(); right++) {
				if (charsFreq.find(str[right]) == charsFreq.end())
					charsFreq[str[right]] = 1;
				else
					charsFreq[str[right]]++;
				
				int maxRepeated = INT_MIN;
				for (auto item : charsFreq) {
					if (maxRepeated < item.second)
						maxRepeated = item.second;
				}
	
				if (((right - left) + 1 - maxRepeated) > k) {
					charsFreq[str[left]]--;
					left++;
				}
	
				result = max(result, right - left + 1);
			}
	
			return result;
		}
	};
	