// Last updated: 7/24/2025, 8:34:48 AM
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        if (n > 0 && s[0] == '0')
            return 0;
        for (int i = 2; i <= n; i++) {
            int one = s[i - 1] - '0';
            int two = (s[i - 2] - '0') * 10 + one;

            if (two < 27 && two > 9)
                dp[i] += dp[i - 2];
            if (one > 0)
                dp[i] += dp[i - 1];
        }
        return dp[n];
    }
};