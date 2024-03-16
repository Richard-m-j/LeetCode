class Solution {
private:
    bool row[9][9];
    bool col[9][9];
    bool box[3][3][9];

public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                int e = board[i][j] - '0' - 1;
                if (e >= 9 || e < 0)
                    continue;

                if (row[i][e] || col[j][e] || box[i / 3][j / 3][e])
                    return false;
                row[i][e] = true;
                col[j][e] = true;
                box[i / 3][j / 3][e] = true;
            }
        
        return true;
    }
};