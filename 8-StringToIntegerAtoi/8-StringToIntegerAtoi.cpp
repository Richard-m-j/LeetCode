// Last updated: 7/24/2025, 8:36:46 AM
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if (s[i] == '+' || s[i] == '-')
            sign = (s[i++] == '-') ? -1 : 1;

        long long result = 0;
        while (isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');
            if (result * sign > INT_MAX)
                return INT_MAX;
            if (result * sign < INT_MIN)
                return INT_MIN;
        }

        return result * sign;
    }
};