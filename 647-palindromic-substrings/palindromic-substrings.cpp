class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        unordered_map<string,bool> dp;
        int count = 0;

        // Single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[s.substr(i, 1)] = true;
            count++;
        }

        // Check palindromic substrings of length 2 or more
        for (int len = 2; len <= n; len++) {
            for (int start = 0; start <= n - len; start++) {
                int end = start + len - 1;
                string sub = s.substr(start, len);
                if ((s[start] == s[end]) && (len == 2 || dp[sub.substr(1, len - 2)])) {
                    dp[sub] = true;
                    count++;
                }
            }
        }

        return count;
    }
};