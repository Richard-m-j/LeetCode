// Last updated: 7/24/2025, 8:35:36 AM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res[j][n - 1 - i] = matrix[i][j];

        matrix = res;
    }
};