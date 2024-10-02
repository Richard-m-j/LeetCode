class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int, int>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            pq.push({-arr[i], i});
        }
        int i = 0;
        int prev = INT_MAX;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if (-it.first != prev)
                i++;
            prev = -it.first;
            arr[it.second] = i;
        }
        return arr;
    }
};