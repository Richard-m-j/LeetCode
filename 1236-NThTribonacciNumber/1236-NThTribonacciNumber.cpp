// Last updated: 7/24/2025, 8:27:47 AM
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n<=2)
            return 1;
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        dp.push_back(1);
        for(int i=3;i<=n;i++)
            dp.push_back(dp[i-1]+dp[i-2]+dp[i-3]);
        return dp[n];
    }
};