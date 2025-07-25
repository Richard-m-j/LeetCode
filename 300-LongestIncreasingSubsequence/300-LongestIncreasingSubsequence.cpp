// Last updated: 7/24/2025, 8:31:54 AM
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int res = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
                    res = max(res,dp[i]);
            }
        }
        return res;
    }
};