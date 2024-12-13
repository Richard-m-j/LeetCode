class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});
        unordered_set<int> marked;
        long long res = 0;
        while (marked.size() != n && !pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();
            if (marked.count(idx))
                continue;
            res += num;
            marked.insert(idx);
            if (idx - 1 >= 0)
                marked.insert(idx - 1);
            if (idx + 1 < n)
                marked.insert(idx + 1);
        }
        return res;
    }
};