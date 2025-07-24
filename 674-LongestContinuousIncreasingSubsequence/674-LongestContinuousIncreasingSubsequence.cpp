// Last updated: 7/24/2025, 8:29:48 AM
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int res = 1, curr = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] > nums[i - 1]) {
                curr++;
                res = max(res, curr);
            } else
                curr = 1;
        return res;
    }
};