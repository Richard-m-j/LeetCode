class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = arr.size();
        vector<int> dp(n, 0);

        int r, maxIndex = n - 1;
        dp[n - 1] = arr[n - 1];

        for (r = n - 2; r >= 0; r--) {
            int maxElement = arr[r];
            dp[r] = arr[r];
            for (int l = 1; l <= k && r + l <= n; l++) { 
                maxElement = max(maxElement, arr[r + l - 1]); 
                if (r >= n - k)
                    dp[r] = max(maxElement * (l), dp[r]); 
                else
                    dp[r] = max(maxElement * (l) + dp[r + l], dp[r]);
            }
        }

        return dp[0];
    }
};