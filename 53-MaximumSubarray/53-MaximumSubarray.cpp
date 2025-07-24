// Last updated: 7/24/2025, 8:35:33 AM
int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        int res = dp[0];
        for(int i =1;i<nums.size();i++){
            dp[i] = nums[i] + max(dp[i-1],0);
            res = max(dp[i],res);
        }
        return res;        
    }
};