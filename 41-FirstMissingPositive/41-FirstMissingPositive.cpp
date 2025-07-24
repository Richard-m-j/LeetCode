// Last updated: 7/24/2025, 8:35:46 AM
int speedUp = [] { ios::sync_with_stdio(0); cin.tie(0); return 0; }();

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = n + 1;

        for (int i = 0; i < n; i++) {
            int num = (nums[i] < 0) ? -nums[i] : nums[i];

            if (num > n)
                continue;
            num--;
            if (nums[num] > 0)
                nums[num] = -nums[num];
        }

        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                return i + 1;
        return n + 1;
    }
};
