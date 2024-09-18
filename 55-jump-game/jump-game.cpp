class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];

        for(int i=1;i<nums.size();i++){
            if(i>dp[i-1])
                return false;
            dp[i] = max(dp[i-1],nums[i]+i);
        }
        return true;
    }
};