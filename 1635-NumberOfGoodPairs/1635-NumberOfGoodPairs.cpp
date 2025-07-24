// Last updated: 7/24/2025, 8:26:28 AM
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i]==nums[j] && i<j)
                    ans++;
                else
                    continue;

            }
        }
        return ans;
    }
};