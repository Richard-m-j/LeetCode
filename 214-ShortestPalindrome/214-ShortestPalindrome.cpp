// Last updated: 7/24/2025, 8:32:51 AM
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        // Create a new string that is `s + # + reverse(s)`
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string new_s = s + "#" + rev_s;

        // Compute the KMP table (prefix function)
        vector<int> kmp(new_s.size(), 0);
        for (int i = 1; i < new_s.size(); ++i) {
            int j = kmp[i - 1];  // Previous longest prefix length
            while (j > 0 && new_s[i] != new_s[j]) {
                j = kmp[j - 1];  // Fall back to the previous matching prefix
            }
            if (new_s[i] == new_s[j]) {
                j++;
            }
            kmp[i] = j;
        }

        // The length of the longest palindromic prefix is the value of the last element in the KMP table
        int palin_len = kmp.back();

        // The characters after the palindromic prefix (suffix that needs to be reversed and prepended)
        string suffix = s.substr(palin_len);
        reverse(suffix.begin(), suffix.end());

        // Return the reversed suffix + original string
        return suffix + s;
    }
};
