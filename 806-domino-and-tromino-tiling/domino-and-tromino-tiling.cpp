class Solution {
public:
    int numTilings(int n) {
        if (n <= 2)
            return n;
        vector<int> dp(n + 2, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        int MOD = 1e9 + 7;
        for (int i = 3; i < n + 2; i++) {
            dp[i] = ((dp[i - 1] * 2) % MOD + dp[i - 3]) % MOD;
        }
        return dp[n + 1];
    }
};
/*
    n=1 1
    n=2 2
    n=3 5

*/