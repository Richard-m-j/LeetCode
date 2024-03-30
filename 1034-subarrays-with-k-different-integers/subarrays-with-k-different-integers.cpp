class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;

            while (l <= r && mp.size() > k) {
                if (--mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};