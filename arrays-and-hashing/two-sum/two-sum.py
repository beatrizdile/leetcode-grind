class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # we create a hashmap that starts out empty, we'll add to it as we advance in the list
        hashmap = {}
        for i, n in enumerate(nums): # enumerate allows to access the index(i) and the value(n) in nums list
            # the only other possible match we're looking for will be the difference between the target and our current value
            diff = target - n
            if diff in hashmap: # if we find the value we're looking for in the hashmap, we got it!
                return [hashmap[diff], i]
            hashmap[n] = i # if we don't find, we'll add the value and index into the hashmap



solution = Solution()
my_list = [3,4,5,6]
target = 7

result = solution.twoSum(my_list, target)
print(f"result: {result}")
