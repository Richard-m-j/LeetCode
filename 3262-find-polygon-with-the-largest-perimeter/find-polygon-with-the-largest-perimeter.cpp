class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(), nums.end());
        long long sum = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
            sum += nums[i];

        for (int i = nums.size() - 1; i >= 0; i--)
            if (nums[i] >= sum - nums[i])
                sum -= nums[i];

        return sum == 0? -1: sum;
    }
};