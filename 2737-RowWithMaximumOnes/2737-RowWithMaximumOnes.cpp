// Last updated: 7/24/2025, 8:23:20 AM
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = mat.size();
        vector<int> rowSum(n,0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            rowSum[i] = accumulate(mat[i].begin(), mat[i].end(), 0);
            if(rowSum[res]<rowSum[i])
                res = i;
        }
        return {res,rowSum[res]};
    }
};