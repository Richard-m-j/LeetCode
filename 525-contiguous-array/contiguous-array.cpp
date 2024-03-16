class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        if (n == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1; 
        int sum = 0;
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            sum += (nums[i] == 0) ? -1 : 1;

            if (mp.find(sum) != mp.end()) {
                maxLength = max(maxLength, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLength;
    }
};
