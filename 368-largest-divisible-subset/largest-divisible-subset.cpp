class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>());
        sort(nums.begin(), nums.end());
        dp[0] = {nums[0]};
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if(dp[i].size()<dp[j].size()+1){
                        dp[i] = dp[j];
                    }
                }
            }
            dp[i].push_back(nums[i]);
            maxIndex = dp[i].size() > dp[maxIndex].size()? i: maxIndex;
        }
        return dp[maxIndex];
    }
};