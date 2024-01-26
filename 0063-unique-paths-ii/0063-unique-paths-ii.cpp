static const int speedUp = []{ios::sync_with_stdio(0);cin.tie(0); return 0;}();
class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<int>> dp;
    int m,n;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        m = grid.size();
        n = grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        dp[m-1][n-1] = 1;
        return helper(0,0);
    }
    int helper(int row, int col)
    {
        if(row == m || row < 0 || col == n || col < 0 || grid[row][col] == 1)
            return 0;
        if(dp[row][col] != -1)
            return dp[row][col];
        dp[row][col] = helper(row+1, col) + helper(row,col+1);
        return dp[row][col];
    }
};