#include <vector>
using namespace std;

class Solution {
private:
    int m, n, numFree = 1, walk = 0;
    pair<int, int> start, end;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start = {i, j};
                } else if (grid[i][j] == 2) {
                    end = {i, j};
                } else if (grid[i][j] == 0) {
                    numFree++;
                }
            }
        }

        vector<vector<int>> visited(m, vector<int>(n, 0));
        dfs(grid, visited, start.first, start.second);
        return ans;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col) {
        if (row == end.first && col == end.second) {
            if(walk == numFree)
                ans++;
        }

        int result = 0;
        visited[row][col] = 1;
        walk++;

        for (const auto& direction : directions) {
            int newRow = row + direction.first;
            int newCol = col + direction.second;

            if (isValid(newRow, newCol) && !visited[newRow][newCol] && grid[newRow][newCol] != -1) {
                dfs(grid, visited, newRow, newCol);
            }
        }

        visited[row][col] = 0;
        walk--;
    }

    bool isValid(int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};
