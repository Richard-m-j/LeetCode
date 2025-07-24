// Last updated: 7/24/2025, 8:32:46 AM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int,int> mp;
        for(auto num: nums)
            if(!mp[num])
                mp[num]++;
            else
                return true;
        return false;
    }
};