static const int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;
        
        vector<string> rows(numRows);
        int rowIndex = 0;
        bool goingDown = false;
        
        for (char &c : s) {
            rows[rowIndex] += c;
            
            if (rowIndex == 0 || rowIndex == numRows - 1) goingDown = !goingDown;
            rowIndex += goingDown ? 1 : -1;
        }
        
        string result;
        for (string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
