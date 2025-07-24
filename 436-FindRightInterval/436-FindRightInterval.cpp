// Last updated: 7/24/2025, 8:30:57 AM
static const int speedUp = []{ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);
        sort(intervals.begin(), intervals.end(), compareStart);

        for (int i = 0; i < n; ++i) {
            int target = intervals[i][1];
            int l = i, r = n - 1, result = -1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (intervals[m][0] >= target) {
                    result = intervals[m][2];
                    r = m - 1;
                } else
                    l = m + 1;
            }
            res[intervals[i][2]] = result;
        }
        return res;
    }

    static bool compareStart(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};
