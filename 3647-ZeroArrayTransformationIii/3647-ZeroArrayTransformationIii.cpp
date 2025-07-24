// Last updated: 7/24/2025, 8:22:12 AM
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int m = queries.size();
        int n = nums.size();

        sort(queries.begin(), queries.end());
        priority_queue<int> available;
        priority_queue<int, vector<int>,greater<int>> used;

        int t = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!used.empty() && used.top() < i)
                used.pop();
            while (j < queries.size() && queries[j][0] == i) {
                available.push(queries[j][1]);
                j++;
            }
            while (nums[i] > used.size() && !available.empty()) {
                auto q = available.top();

                available.pop();
                if (q >= i) {
                    used.push(q);
                    t++;
                }

            }
            if(nums[i]>used.size())
                return -1;
        }
        // cout<<t;
        return m - t;
    }
};