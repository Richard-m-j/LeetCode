class Solution {
private:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int m, n;

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Run DFS for 'O's on the border and mark them as visited
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, visited, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, visited, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, visited, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, visited, m - 1, j);
        }

        // Flip unvisited 'O's to 'X's and visited 'O's back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col) {
        if (visited[row][col]) return;
        visited[row][col] = true;
        for (int d = 0; d < 4; d++) {
            int newR = row + dir[d];
            int newC = col + dir[d + 1];
            if (newR >= 0 && newR < m && newC >= 0 && newC < n && board[newR][newC] == 'O') {
                dfs(board, visited, newR, newC);
            }
        }
    }
};