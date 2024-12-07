class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
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