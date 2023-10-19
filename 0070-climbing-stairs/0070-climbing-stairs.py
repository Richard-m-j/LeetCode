class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 0:
            return 0
        elif n == 1:
            return 1

        fib_0 = 0
        fib_1 = 1

        for i in range(2, n + 2):
            fib_n = fib_0 + fib_1
            fib_0, fib_1 = fib_1, fib_n

        return fib_1