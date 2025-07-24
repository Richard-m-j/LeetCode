// Last updated: 7/24/2025, 8:36:56 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map <int,int> hash;
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int key = target - nums[i];
            if(hash.find(key) != hash.end())
                return {i,hash[key]};
            hash[nums[i]] = i;
        }
        return {};
    }
};