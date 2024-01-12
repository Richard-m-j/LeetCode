class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        if (n > 12 || n < 4) {
            return {};
        }

        auto is_valid = [](const string& num_str) {
            int num = stoi(num_str);
            return num >= 0 && num <= 255 && to_string(num) == num_str;
        };

        vector<string> ans;

        for (int i = 1; i < min(4, n - 2); ++i) {
            for (int j = i + 1; j < min(i + 4, n - 1); ++j) {
                for (int k = j + 1; k < min(j + 4, n); ++k) {
                    string num1 = s.substr(0, i);
                    string num2 = s.substr(i, j - i);
                    string num3 = s.substr(j, k - j);
                    string num4 = s.substr(k);

                    if (is_valid(num1) && is_valid(num2) && is_valid(num3) && is_valid(num4)) {
                        ans.push_back(num1 + "." + num2 + "." + num3 + "." + num4);
                    }
                }
            }
        }

        return ans;
    }
};
