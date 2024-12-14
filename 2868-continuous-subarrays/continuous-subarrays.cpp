class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long res = 0;
        deque<int> mins, maxs;
        int n = nums.size(), l = 0;

        for (int r = 0; r < n; ++r) {
            // Maintain increasing order in mins for the current window
            while (!mins.empty() && nums[r] < nums[mins.back()])
                mins.pop_back();
            mins.push_back(r);

            // Maintain decreasing order in maxs for the current window
            while (!maxs.empty() && nums[r] > nums[maxs.back()])
                maxs.pop_back();
            maxs.push_back(r);

            // Shrink window if condition is violated
            while (nums[maxs.front()] - nums[mins.front()] > 2) {
                if (mins.front() == l) mins.pop_front();
                if (maxs.front() == l) maxs.pop_front();
                ++l;
            }

            // For a valid window, all subarrays ending at 'r' are valid
            res += (r - l + 1);
        }

        return res;
    }
};