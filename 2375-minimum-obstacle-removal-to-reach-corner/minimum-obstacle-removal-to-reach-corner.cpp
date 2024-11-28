class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;
        q.push({0, 0});
        dp[0][0] = 0;
        while (q.size()) {
            int qLen = q.size();
            for (int i = 0; i < qLen; i++) {
                auto node = q.front();
                q.pop();
                int x = node.first;
                int y = node.second;
                for (auto& d : dirs) {
                    int nx = x + d.first;
                    int ny = y + d.second;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                        dp[x][y] + grid[nx][ny] <dp[nx][ny]) {
                        dp[nx][ny] = dp[x][y] + grid[nx][ny];
                        q.push({nx, ny});
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};