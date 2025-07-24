// Last updated: 7/24/2025, 8:25:24 AM
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long res = 0;
        int n = matrix.size();
        int countCol = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            int minIdx = 0;
            int countRow = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0) {
                    matrix[i][j] *= -1;
                    countRow++;
                }
                if (matrix[i][j] < matrix[x][y]){
                    x = i;
                    y = j;
                }
                res += matrix[i][j];
            }
            if (countRow % 2)
                countCol++;
        }
        //14 13 7
        // cout<<res<<" ";
        if (countCol % 2) {
            res -= matrix[x][y] * 2;
        }
        return res;
    }
};