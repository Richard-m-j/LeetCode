// Last updated: 7/24/2025, 8:31:53 AM
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
            for (int& c : coins)
                if (i - c >= 0)
                    dp[i] = min(dp[i], dp[i - c] + 1);
        if (dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};