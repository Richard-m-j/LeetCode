// Last updated: 7/24/2025, 8:26:06 AM
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        vector<int> dp1(n, 0), dp2(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp1[i] < dp1[j] + 1)
                    dp1[i] = dp1[j] + 1;
                if (nums[n-i-1] > nums[n-j-1] && dp2[n-i-1] < dp2[n-j-1] + 1)
                    dp2[n-i-1] = dp2[n-j-1] + 1;
            }
        } 
        int res = n;
        for (int i = 1; i < n - 1; i++) {
            if(!dp1[i] || !dp2[i])
                continue;
            res = min(res, n - dp1[i] - dp2[i] - 1);
            // cout << dp1[i] << " " <<dp2[i]<<" "<< val <<endl;
        }
        return res;
    }
};