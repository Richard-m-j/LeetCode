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
        dp.resize(m+1,vector<int>(n+1,0));
        dp[0][1] = 1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(!grid[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};