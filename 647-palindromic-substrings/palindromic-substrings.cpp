class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (s[j] == s[i]) {
                    string sub = s.substr(j, i - j + 1);
                    string rev = sub;
                    reverse(rev.begin(), rev.end());
                    if (rev == sub)
                        count++;
                }
            }
            count++;
        }
        return count;
    }
};