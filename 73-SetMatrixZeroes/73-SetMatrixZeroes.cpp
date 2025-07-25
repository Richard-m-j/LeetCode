// Last updated: 7/24/2025, 8:35:09 AM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstCol = false;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                firstCol = true;
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--)
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            if (firstCol)
                matrix[i][0] = 0;
        }
    }
};