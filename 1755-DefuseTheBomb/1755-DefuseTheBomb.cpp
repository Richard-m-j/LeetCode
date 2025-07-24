// Last updated: 7/24/2025, 8:26:11 AM
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (!k)
            return res;
        if (k > 0) {
            for (int j = 1; j != (k + 1) % n; j = (j + 1) % n)
                res[0] += code[j];
            for (int i = 1; i < n; i++)
                res[i] = res[i - 1] - code[i] + code[(i + k) % n];

        } else {
            for (int j = n - 1; j != (k - 1 + n) % n; j = (j - 1 + n) % n)
                res[0] += code[j];
            for (int i = 1; i < n; i++)
                res[i] = res[i - 1] + code[i - 1] - code[(i + k - 1 + n) % n];
        }
        return res;
    }
};