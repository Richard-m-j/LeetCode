// Last updated: 7/24/2025, 8:23:44 AM
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<int> pq;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        for (int i = 0; i < k; i++) {
            auto val = pq.top();
            pq.pop();

            res += val;
            // cout<<val<<" ";
            pq.push(ceil(val / 3.0));
        }
        return res;
    }
};