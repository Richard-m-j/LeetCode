# Last updated: 7/24/2025, 8:29:32 AM
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0]*n
        stack = deque()
        stack.append(n-1)

        for i in range(n-2,-1,-1):
            while len(stack) and temperatures[stack[-1]] <= temperatures[i]:
                stack.pop()
            if len(stack):
                res[i] = stack[-1] - i
            stack.append(i)
        return res
