// Last updated: 7/24/2025, 8:28:03 AM
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = arr.size();
        int dp[n + 1]; 

        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int maxElement = arr[i - 1];
            dp[i] = dp[i - 1] + arr[i - 1]; 
            for (int j = 2; j <= k && i - j >= 0; ++j) {
                maxElement = max(maxElement, arr[i - j]); 
                dp[i] = max(dp[i], dp[i - j] + maxElement * j); 
            }
        }
        return dp[n];
    }
};
