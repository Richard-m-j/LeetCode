// Last updated: 7/24/2025, 8:31:39 AM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> mp;
        vector<int> res;
        for (int& num : nums1)
            mp[num] = 1;
        for (int& num : nums2)
            if (mp[num]) {
                mp[num] = false;
                res.push_back(num);
            }
        return res;
    }
};