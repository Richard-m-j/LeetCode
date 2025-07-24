// Last updated: 7/24/2025, 8:33:53 AM
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> path;

        // Precompute a palindrome matrix to check if substrings are palindromes efficiently.
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        function<void(int)> dfs = [&](int start) {
            if (start == n) {
                res.push_back(path);
                return;
            }
            for (int end = start; end < n; end++) {
                if (isPalindrome[start][end]) {
                    path.push_back(s.substr(start, end - start + 1));
                    dfs(end + 1);
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};
