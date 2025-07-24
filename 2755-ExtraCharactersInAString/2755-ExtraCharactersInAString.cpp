// Last updated: 7/24/2025, 8:23:19 AM
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            for (auto& w : dictionary) {
                if (i + w.length() <= n && s.substr(i, w.length()) == w){
                    dp[i] = min(dp[i], dp[i + w.length()]);
                    // cout<<dp[i]<<"-"<<w<<" ";
                }
            }
            // cout << dp[i] << "\n";
        }
        return dp[0];
    }
};