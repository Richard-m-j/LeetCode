// Last updated: 7/24/2025, 8:30:25 AM
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++) {
                if (!mat[i][j]) {
                    q.push({i, j});
                    dp[i][j] = 0;
                }
            }
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int x = curr.first + dir.first;
                int y = curr.second + dir.second;
                if (x >= 0 && y >= 0 && x < n && y < m) {
                    if (dp[x][y] > dp[curr.first][curr.second] + 1) {
                        dp[x][y]=dp[curr.first][curr.second] + 1;
                        q.push({x,y});
                    }
                }
            }
        }
        return dp;
    }
};