# Two Integer Sum

Given an array of integers `nums` and an integer `target`, return the indices `i` and `j` such that `nums[i] + nums[j] == target` and `i != j`.

You may assume that every input has exactly one pair of indices `i` and `j` that satisfy the condition.

Return the answer with the smaller index first.

## Examples

### Example 1:

```python
Input: 
nums = [3,4,5,6], target = 7

Output: 
[0,1]
```

Explanation: `nums[0] + nums[1] == 7`, so we return `[0, 1]`.

### Example 2:

```python
Input:
nums = [4,5,6], target = 10

Output: 
[0,2]
```

### Example 3:

```python
Input:
nums = [5,5], target = 10

Output: 
[0,1]
```

### Constraints:
* ```python 2 <= nums.length <= 1000```

* ```python -10,000,000 <= nums[i] <= 10,000,000```

* ```python -10,000,000 <= target <= 10,000,000```
