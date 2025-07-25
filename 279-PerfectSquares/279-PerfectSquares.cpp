// Last updated: 7/24/2025, 8:32:04 AM
class Solution {
public:
    int numSquares(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for (int i = 1; i * i <= n; i++)
            dp[i * i] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};