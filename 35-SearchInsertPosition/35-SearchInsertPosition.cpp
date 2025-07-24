// Last updated: 7/24/2025, 8:35:57 AM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }
};