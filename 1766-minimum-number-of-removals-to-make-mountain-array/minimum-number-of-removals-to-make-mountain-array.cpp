class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 0), dp2(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp1[i] < dp1[j] + 1)
                    dp1[i] = dp1[j] + 1;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j] && dp2[i] < dp2[j] + 1)
                    dp2[i] = dp2[j] + 1;
            }
        }
        int res = n;
        for (int i = 1; i < n - 1; i++) {
            if(!dp1[i] || !dp2[i])
                continue;
            int val = n - dp1[i] - dp2[i] - 1;
            res = min(res, val);
            cout << dp1[i] << " " <<dp2[i]<<" "<< val <<endl;
        }
        return res;
    }
};