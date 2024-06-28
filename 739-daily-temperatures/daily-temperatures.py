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

# [73,74,75,71,69,72,76,73]
# [01,01,04,02,01,01,00,00]