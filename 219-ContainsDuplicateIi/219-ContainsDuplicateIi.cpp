// Last updated: 7/24/2025, 8:32:44 AM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]) && i-mp[nums[i]] <= k)
                    return true;
            else
                mp[nums[i]] = i;
        }
        return false;
    }
};