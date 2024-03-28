class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int, int> freq;
        int ans = 0;
        bool flag = false;
        int l = 0, r = 0, n = nums.size();
        for (; r < n; r++) {
            if (++freq[nums[r]] > k) {
                flag = true;
            }
            while (flag && l <= r) {
                freq[nums[l]]--;
                ans = max(ans, r - l);
                l++;
                if(freq[nums[r]] == k) flag = false;
            }
        }
        ans = max(ans, r - l);
        
        return ans;
    }
};
