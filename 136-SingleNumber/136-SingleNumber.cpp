// Last updated: 7/24/2025, 8:33:52 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans = 0;
        for (int num : nums)
            ans = ans ^ num;
        return ans;
    }
};