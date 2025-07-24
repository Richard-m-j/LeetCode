# Last updated: 7/24/2025, 8:33:33 AM
class Solution:
    def findMin(self, nums: List[int]) -> int:
        l=0
        r=len(nums)-1
        minimum = nums[0]
        while l <= r:
            m = l + (r-l)//2
            minimum = min(minimum,nums[m])
            if nums[l] < nums[m]:
                minimum = min(nums[l],minimum)
                l = m+1
            else:
                minimum = min(nums[r],minimum)
                r = m - 1
        return minimum
