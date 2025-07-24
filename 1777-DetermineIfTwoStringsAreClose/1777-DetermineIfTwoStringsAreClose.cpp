// Last updated: 7/24/2025, 8:26:03 AM
int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int f1[26] = {};
        int f2[26] = {};
        if (word1.length() != word2.length())
            return false;

        for (char i : word1)
            f1[i - 'a']++;

        for (char i : word2)
            f2[i - 'a']++;

        for (int i = 0; i < 26; i++)
            if (f1[i] > 0 && !f2[i] || f2[i] > 0 && !f1[i])
                return false;

        sort(f1, f1 + 26);
        sort(f2, f2 + 26);

        for (int i = 0; i < 26; i++)
            if (f1[i] != f2[i])
                return false;

        return true;
    }
};