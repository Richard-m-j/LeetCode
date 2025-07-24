// Last updated: 7/24/2025, 8:22:22 AM
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = b.size();
        vector<vector<long long>> dp(5, vector<long long>(n+1, LLONG_MIN));
        
        for (int i = 0; i <= n; ++i) 
            dp[0][i] = 0;
        
        
        for (int k = 1; k <= 4; ++k) 
            for (int j = k; j <= n; ++j) 
                dp[k][j] = max(dp[k][j-1], dp[k-1][j-1] + (long long)a[k-1] * b[j-1]);

        return dp[4][n];
    }
};