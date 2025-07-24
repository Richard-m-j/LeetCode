// Last updated: 7/24/2025, 8:32:43 AM
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res,matrix[i][0]-'0');
            dp[i][0] = matrix[i][0]-'0';
        }
        for(int i=0;i<m;i++){
            res = max(res,matrix[0][i]-'0');
            dp[0][i] = matrix[0][i]-'0';
        }
        // cout<<res;
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(matrix[i][j]-'0'){
                    int square = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                    res = max(res,square*square);
                    dp[i][j] = square;
                }
        // cout<<matrix[n-1][m-1]<<" ";
        return res;
    }
};