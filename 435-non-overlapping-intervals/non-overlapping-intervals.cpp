class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // sort the intervals
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 return a[1] < b[1];
             });
        int res = 0;
        int l = intervals[0][0];
        int r = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] == l || intervals[i][0] < r) {
                r = min(r, intervals[i][1]);
                res++;
            } else {
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        return res;
    }
};