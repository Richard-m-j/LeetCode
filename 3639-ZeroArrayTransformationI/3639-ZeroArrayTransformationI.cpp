// Last updated: 7/24/2025, 8:22:06 AM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (auto& q : queries) {
            prefix[q[0]] -= 1;
            if (q[1] < n - 1)
                prefix[q[1] + 1] += 1;
        }
        if (prefix[0] + nums[0] > 0)
            return false;
        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] += prefix[i - 1];
            if (prefix[i] + nums[i] > 0)
                return false;
        }
        return true;
    }
};