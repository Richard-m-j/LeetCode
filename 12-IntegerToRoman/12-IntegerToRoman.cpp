// Last updated: 7/24/2025, 8:36:40 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    string intToRoman(int num) {
        const vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const vector<string> numerals = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        
        for (int i = 0; num >0; ++i) {
            while (num >= values[i]) {
                result += numerals[i];
                num -= values[i];
            }
        }

        return result;
    }
};
