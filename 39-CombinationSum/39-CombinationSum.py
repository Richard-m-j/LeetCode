# Last updated: 7/24/2025, 8:36:01 AM
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = set()

        def helper(current, currentSum):
            for num in candidates:
                nextSum = currentSum + num
                if nextSum == target:
                    res.add(tuple(sorted(current + [num])))
                elif nextSum < target:
                    helper(current + [num], nextSum)

        helper([], 0)
        return [list(combination) for combination in res]
