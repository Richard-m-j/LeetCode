class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = matrix.size();
        int m = matrix[0].size();
        // find upper bound row
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l+r)/ 2;
            if (matrix[m][0] == target)
                return true;
            if (matrix[m][0] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        // cout<<l<<endl;
        for (int i = l; i >= 0; i--) {
            int mid = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            // if(mid<m)
            //     cout<<i<<" "<<mid<<" "<<matrix[i][mid]<<endl;
            if (mid < m && matrix[i][mid] == target)
                return true;
        }
        return false;
    }
};