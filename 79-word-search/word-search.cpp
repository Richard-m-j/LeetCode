class Solution {
private:
    vector<vector<char>> board;
    string word;
    int m, n;
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    bool exist(vector<vector<char>>& board, string word) {
        Solution::board = board;
        Solution::word = word;
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bool val = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word[0] == board[i][j]) {
                    val = val || checkNear(visited, i, j, 0);
                    if (val) return true; // Return immediately if solution found
                }
            }
        }
        return false;
    }

    bool checkNear(vector<vector<bool>>& visited, int row, int col, int k) {
        if (k == word.length())
            return true;
        if (row < 0 || row == n || col < 0 || col == m)
            return false;
        if (visited[row][col] || board[row][col] != word[k])
            return false;

        visited[row][col] = true;
        bool ans = false;
        for (auto& it : dir) {
            ans = ans || checkNear(visited, row + it[0], col + it[1], k + 1);
            if (ans) break; // Break early if solution found
        }
        visited[row][col] = false; // Reset the visited state after recursive calls
        return ans;
    }
};
