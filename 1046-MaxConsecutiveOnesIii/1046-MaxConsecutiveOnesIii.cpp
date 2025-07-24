// Last updated: 7/24/2025, 8:28:08 AM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int flip = k, l = 0, r = 0, res = 0;
        while (r < nums.size()) {
            if (!nums[r])
                if (flip)
                    flip--;
                else
                    while (nums[l++])
                        ;

            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};