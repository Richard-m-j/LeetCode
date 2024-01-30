class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s; // Edge case: If numRows is 1, return the input string

        int numCols = s.length();
        vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));
        int row = 0, col = 0;
        bool goingDown = false;

        for (char c : s) {
            matrix[row][col] = c;

            if (row == 0 || row == numRows - 1)
                goingDown = !goingDown;
            row += goingDown ? 1 : -1;
            col++;
        }

        string res = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (matrix[i][j] != ' ') {
                    res += matrix[i][j];
                }
            }
        }

        return res;
    }
};