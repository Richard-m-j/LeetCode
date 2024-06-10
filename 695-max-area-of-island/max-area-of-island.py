class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid[0])
        n = len(grid)
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]
        def dfs(grid,row,col):
            grid[row][col]=0
            area = 1
            for dir in dirs:
                nextR = row + dir[0]
                nextC = col + dir[1]
                if 0<=nextR<n and 0<=nextC<m and grid[nextR][nextC]:
                    area += dfs(grid,nextR,nextC)
            return area
        
        maxArea = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    maxArea = max(dfs(grid,i,j),maxArea)
        return maxArea
