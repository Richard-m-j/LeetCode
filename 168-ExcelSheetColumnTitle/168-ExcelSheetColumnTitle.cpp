// Last updated: 7/24/2025, 8:33:24 AM
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber) {
            int d = (columnNumber - 1) % 26;
            columnNumber = (columnNumber - 1) / 26;
            res = (char)(d+'A') + res;
        }
        return res;
    }
};