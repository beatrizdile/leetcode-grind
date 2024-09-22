class Solution:
    def hasDuplicate(self, nums: list[int]) -> bool:
        # hashmap for counting every numbers apparition
        numsCount = {}
        for num in nums:
            if num in numsCount and numsCount[num] != 1:
                return True
            else:
                numsCount[num] = 1 + numsCount.get(num, 0)
        
        for key in numsCount:
            if numsCount[key] != 1:
                return True

        return False



solution = Solution()
nums1 = [1, 2, 3, 3]
nums2 = [1, 2, 3, 4]

result = solution.hasDuplicate(nums1)
print(f"hasDuplicate result for {nums1}: {result}")
result = solution.hasDuplicate(nums2)
print(f"hasDuplicate result for {nums2}: {result}")
