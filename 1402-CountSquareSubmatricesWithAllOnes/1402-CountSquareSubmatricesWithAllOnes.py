# Last updated: 7/24/2025, 8:27:27 AM
class Solution(object):
    def countSquares(self, matrix):
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * (n+1) for _ in range(m+1)] # new int[m+1][n+1];
        ans = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j]:
                    dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j], dp[i][j]) + 1
                    ans += dp[i+1][j+1]
        return ans