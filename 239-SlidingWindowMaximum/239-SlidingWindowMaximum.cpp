// Last updated: 7/24/2025, 8:32:19 AM
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // Using deque to store indices of array elements
        
        deque<int> deq;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            if (!deq.empty() && deq.front() == i - k) {
                deq.pop_front();
            }

            while (!deq.empty() && nums[deq.back()] < nums[i]) {
                deq.pop_back();
            }

            deq.push_back(i);

            if (i >= k - 1) {
                res.push_back(nums[deq.front()]);
            }
        }

        return res;
    }
};