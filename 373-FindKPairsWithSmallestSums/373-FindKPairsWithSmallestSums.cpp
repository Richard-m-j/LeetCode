// Last updated: 7/24/2025, 8:31:32 AM
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int& num : nums1)
            pq.push({num + nums2[0], 0});

        while (k--) {
            int sum = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            res.push_back({sum - nums2[pos], nums2[pos]});

            if (pos + 1 < nums2.size())
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
        }

        return res;
    }
};