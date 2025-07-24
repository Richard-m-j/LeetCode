// Last updated: 7/24/2025, 8:30:02 AM
static const int speedUp = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();

class Solution {
private:
    const int MOD = 1000000007;

public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> prefixSum(k + 1, 0);
            prefixSum[0] = dp[i - 1][0];
            for (int j = 1; j <= k; j++) {
                prefixSum[j] = (prefixSum[j - 1] + dp[i - 1][j]) % MOD;
            }

            for (int j = 0; j <= k; j++) {
                int lower = max(0, j - i + 1);
                dp[i][j] = (prefixSum[j] - (lower > 0 ? prefixSum[lower - 1] : 0) + MOD) % MOD;
            }
        }

        return dp[n][k];
    }
};
