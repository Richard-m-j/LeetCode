class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        count = 0
        prefix_sum = {0: 1}  # Store the count of prefix sums encountered so far
        current_sum = 0

        for num in nums:
            current_sum += num
            count += prefix_sum.get(current_sum - goal, 0)  # Add count of subarrays with sum (current_sum - goal)

            prefix_sum[current_sum] = prefix_sum.get(current_sum, 0) + 1  # Update the prefix sum count

        return count
