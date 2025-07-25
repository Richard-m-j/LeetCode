// Last updated: 7/24/2025, 8:30:34 AM
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        if (nums.size() < 2)
            return false;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int accumulated = 0;
        for (int i = 0; i < nums.size(); i++) {
            accumulated += nums[i];
            int mod = accumulated % k;
            if (mp.find(mod) != mp.end()) {
                if (i - mp[mod] > 1)
                    return true;
            } else
                mp[mod] = i;
        }
        return false;
    }
};