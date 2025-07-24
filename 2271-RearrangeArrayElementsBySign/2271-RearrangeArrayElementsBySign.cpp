// Last updated: 7/24/2025, 8:24:45 AM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector<int> res(n);
        int i = 0, j = 1;
        for (int k = 0; k < n; k++) {
            if (nums[k] > 0) {
                res[i] = nums[k];
                i += 2;
            } else {
                res[j] = nums[k];
                j += 2;
            }
        }

        return res;
    }
};