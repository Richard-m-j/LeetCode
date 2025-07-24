// Last updated: 7/24/2025, 8:33:20 AM
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int power = 1;
        for (int i = columnTitle.length() - 1; i >= 0; i--) {
            res += (columnTitle[i] - 'A' + 1)*power;
            if(power<INT_MAX/26)
                power *= 26;
        }
        return res;
    }
};