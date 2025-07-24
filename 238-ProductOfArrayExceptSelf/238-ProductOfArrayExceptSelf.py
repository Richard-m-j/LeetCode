# Last updated: 7/24/2025, 8:32:21 AM
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [1] * len(nums)

        for i in range(0, len(nums) - 1):
            prefix[i + 1] = prefix[i] * nums[i]
        suffix = [1] * len(nums)

        for i in range(len(nums) - 2, -1, -1):
            suffix[i] = suffix[i+1] * nums[i+1]
        
        for i in range(len(nums)):
            nums[i] = prefix[i] * suffix[i]

        return nums