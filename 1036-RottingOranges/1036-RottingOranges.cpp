// Last updated: 7/24/2025, 8:28:12 AM
class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = (rows > 0) ? grid[0].size() : 0;
        int freshOranges = 0;
        int minutes = 0;

        std::queue<std::pair<int, int>> rottenOranges;

        // Count fresh oranges and enqueue initial rotten oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    ++freshOranges;
                } else if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                }
            }
        }

        // If there are no fresh oranges initially, return 0
        if (freshOranges == 0) {
            return 0;
        }

        // Perform BFS
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!rottenOranges.empty()) {
            int size = rottenOranges.size();
            for (int i = 0; i < size; ++i) {
                int x = rottenOranges.front().first;
                int y = rottenOranges.front().second;
                rottenOranges.pop();

                for (const auto& dir : directions) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        rottenOranges.push({nx, ny});
                        --freshOranges;
                    }
                }
            }

            if (!rottenOranges.empty()) {
                ++minutes;
            }
        }

        // If there are remaining fresh oranges, return -1; otherwise, return minutes
        return (freshOranges == 0) ? minutes : -1;
    }
};
