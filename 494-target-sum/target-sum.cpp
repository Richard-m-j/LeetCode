class Solution {
private:
    vector<vector<int>> dp;

    int helper(vector<int>& nums, int target, int idx, int sum, int offset) {
        if (idx == nums.size()) {
            return sum == target;
        }
        if (dp[idx][sum + offset] != -1)
            return dp[idx][sum + offset];

        int add = helper(nums, target, idx + 1, sum + nums[idx], offset);
        int sub = helper(nums, target, idx + 1, sum - nums[idx], offset);

        return dp[idx][sum + offset] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > total)
            return 0;

        int offset = total;
        dp.resize(nums.size(), vector<int>(2 * total + 1, -1));

        return helper(nums, target, 0, 0, offset);
    }
};
