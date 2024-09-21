class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        # the first string adds, the second string subtracts
        charMap = {}
        for i in range(len(s)):
            charMap[s[i]] = 1 + charMap.get(s[i], 0)
            charMap[t[i]] = charMap.get(t[i], 0) - 1

        # in the end, the entire hashmap needs to be 0, otherwise, there's a diff
        for key in charMap:
            if charMap[key] != 0:
                return False
        
        return True



solution = Solution()
str1 = "racecar"
str2 = "carrace"

result = solution.isAnagram(str1, str2)
print(f"result: {result}")
