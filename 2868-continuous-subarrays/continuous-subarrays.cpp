class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long res = 0;
        deque<int> mins, maxs;
        int n = nums.size(), left = 0;

        for (int right = 0; right < n; ++right) {
            // Maintain increasing order in mins for the current window
            while (!mins.empty() && nums[right] < nums[mins.back()])
                mins.pop_back();
            mins.push_back(right);

            // Maintain decreasing order in maxs for the current window
            while (!maxs.empty() && nums[right] > nums[maxs.back()])
                maxs.pop_back();
            maxs.push_back(right);

            // Shrink window if condition is violated
            while (nums[maxs.front()] - nums[mins.front()] > 2) {
                if (mins.front() == left) mins.pop_front();
                if (maxs.front() == left) maxs.pop_front();
                ++left;
            }

            // For a valid window, all subarrays ending at 'right' are valid
            res += (right - left + 1);
        }

        return res;
    }
};