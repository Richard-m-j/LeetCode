// Last updated: 7/24/2025, 8:36:00 AM
class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n);
        dp[0] = "1";
        for (int i = 1; i < n; i++) {
            // dp[i]
            string s = dp[i - 1];
            s += '/';
            int count = 1;
            string ans = "";
            for (int j = 0; j < s.length() - 1; j++) {
                if (s[j] == s[j + 1])
                    count++;
                else {
                    ans += count + '0';
                    ans += s[j];
                    count = 1;
                }
            }
            dp[i] = ans;
        }
        return dp[n - 1];
    }
};