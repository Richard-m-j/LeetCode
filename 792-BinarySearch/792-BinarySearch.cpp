// Last updated: 7/24/2025, 8:29:15 AM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};