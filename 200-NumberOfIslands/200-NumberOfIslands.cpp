// Last updated: 7/24/2025, 8:33:04 AM
class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    bfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<char>>& grid,int i,int j) {
        queue<vector<int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int l = q.size();
            for (int k = 0; k < l; k++) {
                auto node = q.front();
                q.pop();
                for (auto dir : dirs) {
                    vector<int> newNode = {node[0] + dir[0],
                                              node[1] + dir[1]};
                    if (newNode[0] >= 0 && newNode[0] < m && newNode[1] >= 0 &&
                        newNode[1] < n && grid[newNode[0]][newNode[1]] == '1') {
                        grid[newNode[0]][newNode[1]] = '0';

                        q.push(newNode);
                    }
                }
            }
        }
    }
};