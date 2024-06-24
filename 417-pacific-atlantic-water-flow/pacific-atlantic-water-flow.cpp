class Solution {
private:
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int m, n;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited,
             int row, int col) {
        if(visited[row][col])
            return;
        visited[row][col] = true;
        for (int d = 0; d < 4; d++) {
            int newRow = row + dirs[d];
            int newCol = col + dirs[d + 1];
            if (newRow < m && newRow >= 0 && newCol < n && newCol >= 0)
                if (heights[row][col] <= heights[newRow][newCol])
                    dfs(heights, visited, newRow, newCol);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false)),
            atlantic(m, vector<bool>(n, false));

        // top to down
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        // left to right
        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m - 1, i);
        }
        vector<vector<int>> ans;
        // compare
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] == 1 && atlantic[i][j] == 1)
                    ans.push_back({i, j});
        
        return ans;
    }
};