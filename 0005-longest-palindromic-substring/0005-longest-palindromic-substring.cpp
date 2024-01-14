class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string longest_palindrome = "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Filling out the diagonal by true
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            longest_palindrome = s[i];
        }

        // Filling the dp table
        for (int i = n - 1; i >= 0; i--) {
            // j starts from the i location: to only work on the upper side of the diagonal
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;

                    // We also need to keep track of the maximum palindromic sequence
                    if (longest_palindrome.length() < j - i + 1) {
                        longest_palindrome = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return longest_palindrome;
    }
};
