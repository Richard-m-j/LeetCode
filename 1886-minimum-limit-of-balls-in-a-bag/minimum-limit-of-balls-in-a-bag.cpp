class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = l + (r - l) / 2;
            int ops = 0;
            for (int n : nums)
                if ((ops += (n - 1) / m) > maxOps)
                    break;
            ops <= maxOps ? r = m : l = m + 1;
        }
        return r;
    }
};