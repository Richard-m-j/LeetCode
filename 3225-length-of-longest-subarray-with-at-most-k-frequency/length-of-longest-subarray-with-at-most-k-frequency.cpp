class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> graph;
        int ans = 0;
        int l = 0, r = 0, n = nums.size();
        for (; r < n; r++) {
            if (++freq[nums[r]] > k) {
                ans = max(ans, r - l);
                int nextL = graph[nums[r]][0];
                while (l <= nextL) {
                    freq[nums[l]]--;
                    graph[nums[l]].erase(graph[nums[l]].begin());
                    l++;
                }
            }
            graph[nums[r]].push_back(r);
        }
        ans = max(ans, r - l);
        
        return ans;
    }
};
