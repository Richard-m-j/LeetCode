// Last updated: 7/24/2025, 8:27:22 AM
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int res = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]){
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + 1;
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};