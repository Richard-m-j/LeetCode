# Last updated: 7/24/2025, 8:36:02 AM
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l,r= 0,len(nums)-1

        while l<=r:
            m = l + (r-l)//2
            if nums[m] == target:
                return m
            # if left is sorted
            if nums[l] <= nums[m]:
                if nums[l] <= target < nums[m]:
                    r = m - 1
                else:
                    l = m + 1
            else:
                if nums[m] < target <= nums[r]:
                    l = m + 1
                else:
                    r = m - 1
        return - 1