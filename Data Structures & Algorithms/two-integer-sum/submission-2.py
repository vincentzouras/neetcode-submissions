class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}

        for i, num in enumerate(nums): 
            result = target - num
            if result in seen:
                return [seen[result], i]
            seen[num] = i
    