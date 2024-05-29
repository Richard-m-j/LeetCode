class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num: nums)
            if(!mp[num])
                mp[num]++;
            else
                return true;
        return false;
    }
};