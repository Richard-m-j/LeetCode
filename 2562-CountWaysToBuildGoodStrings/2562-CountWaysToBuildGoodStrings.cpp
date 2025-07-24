// Last updated: 7/24/2025, 8:23:53 AM
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int mod = 1e9+7;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) 
                dp[i] = (dp[i] + dp[i - zero]) %mod;
            if (i >= one) 
                dp[i] = (dp[i] + dp[i - one]) %mod;
            
        }
        int res = 0 ; 
        for(int i=low;i<=high;i++)
            res = (res + dp[i])%mod;
        return res;
    }
};