// Last updated: 7/24/2025, 8:29:00 AM
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private:
    int res = 0;
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int row[3], col[3], d1, d2;
        unordered_set<int> s;
        for (int k = -1; k < 2; k++) {
            row[k + 1] = grid[i + k][j - 1] + grid[i + k][j] + grid[i + k][j + 1];
            if (grid[i + k][j - 1] < 1 || grid[i + k][j - 1] > 9)
                return;
            if (grid[i + k][j] < 1 || grid[i + k][j] > 9)
                return;
            if (grid[i + k][j + 1] < 1 || grid[i + k][j + 1] > 9)
                return;
            s.insert(grid[i + k][j - 1]);
            s.insert(grid[i + k][j]);
            s.insert(grid[i + k][j + 1]);
            cout<<grid[i + k][j - 1]<<" ";
            col[k + 1] =  grid[i - 1][j + k] + grid[i][j + k] + grid[i + 1][j + k];
        }
        d1 = grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1];
        d2 = grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1];
        // cout<<d1<<" "<<d2<<endl;
        // cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<endl;
        if (s.size() == 9 && row[0] == 15 && row[1] == 15 && row[2] == 15 &&
            col[0] == 15 && col[1] == 15 && col[2] == 15 && d1 == 15 &&
            d2 == 15)
            res++;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[0].size() - 1; j++)
                dfs(grid, i, j);
        }
        return res;
    }
};