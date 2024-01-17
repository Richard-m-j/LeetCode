class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # l=0
        # u=len(nums)-1
        # while l<=u:
        #     m=(l+u)//2
        #     if nums[m]<target:
        #         l=m+1
        #     elif nums[m]>target:
        #         u=m-1
        #     else:
        #         return m
        # return -1
        try:
            return nums.index(target)
        except ValueError:
            return -1