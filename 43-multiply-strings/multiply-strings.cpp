class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size();
        int m = num2.size();
        vector<int> resVec(n + m, 0);

        // Reverse the numbers
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + resVec[i + j];
                resVec[i + j] = sum % 10;
                resVec[i + j + 1] += sum / 10;
            }
        }

        // Remove leading zeros and construct the result
        while (resVec.size() > 1 && resVec.back() == 0) {
            resVec.pop_back();
        }
        
        string result;
        for (auto it = resVec.rbegin(); it != resVec.rend(); ++it) {
            result.push_back('0' + *it);
        }
        
        return result;
    }
};
