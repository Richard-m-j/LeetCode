// Last updated: 7/24/2025, 8:35:21 AM
static const int speedUp = []{ios::sync_with_stdio(0);cin.tie(0); return 0;}();
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        dp[0][1] = 1;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            
        return dp[m][n];
    }
};