#会超出时间限制
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = list()
        for i in range(len(nums)-1):
            for j in range(i+1,len(nums)):
                if target == nums[i] + nums[j]:
                    result.append(i)
                    result.append(j)
        return result