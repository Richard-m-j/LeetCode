// Last updated: 7/24/2025, 8:30:18 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0); return 0;}();
class Solution {
private:
    vector<vector<vector<int>>> dp;
    int m, n;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;

        // Resize the dp vector
        dp.resize(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        int result = numPaths(maxMove, startRow, startColumn);

        return result;
    }

    int numPaths(int maxMove, int row, int col) {
        if (row == m || row < 0 || col == n || col < 0)
            return 1;
        if (maxMove == 0)
            return 0;
        if (dp[row][col][maxMove] != -1)
            return dp[row][col][maxMove];
        int sumPaths = 0;
        for (const auto& dir : directions)
            sumPaths = (sumPaths + numPaths(maxMove - 1, row + dir.first, col + dir.second)) % 1000000007;
        dp[row][col][maxMove] = sumPaths;
        return dp[row][col][maxMove];
    }
};
