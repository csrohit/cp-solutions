
// o(n*n)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i]+nums[j] == target:
                    return [i, j]
                    
                    
                   
// o(n)
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s = dict()
        for i in range(len(nums)):
            if target - nums[i] in s.keys():
                return [s[target - nums[i]], i]
            else:
                s[nums[i]] = i
        