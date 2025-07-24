// Last updated: 7/24/2025, 8:33:57 AM
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '*')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]!='O')
            return;
        board[row][col] = '*';
        dfs(board, row - 1, col);
        dfs(board, row + 1, col);
        dfs(board, row, col - 1);
        dfs(board, row, col + 1);
    }
};