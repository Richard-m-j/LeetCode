class Solution {
public:
    int numSquares(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> dp(n + 1, INT_MAX);
        for (int i = 1; i * i <= n; i++)
            dp[i * i] = 1;
        for (int i = 2; i <= n; i++) {
            if (dp[i] == 1)
                continue;
            for (int j = 1; j <= i / 2; j++)
                dp[i] = min(dp[i], dp[i - j] + dp[j]);
        }
        return dp[n];
    }
};