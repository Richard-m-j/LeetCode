# Last updated: 7/24/2025, 8:33:10 AM
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        n = len(grid)
        m = len(grid[0])

        def dfs(grid, row, col):
            grid[row][col] = "0"
            for dir in dirs:
                nextR = row + dir[0]
                nextC = col + dir[1]
                if 0 <= nextR < n and 0 <= nextC < m and grid[nextR][nextC] == "1":
                    dfs(grid, nextR, nextC)

        numIslands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    numIslands += 1
                    dfs(grid, i, j)
        
        return numIslands
