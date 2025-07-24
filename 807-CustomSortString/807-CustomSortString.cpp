// Last updated: 7/24/2025, 8:29:09 AM
class Solution {
public:
    string customSortString(string order, string s) {
        string str;
        vector<int> mp(26, 0);
        for (char c: s) {
            mp[c - 'a']++;
        }
        for (char c: order) {
            while (mp[c - 'a']) {
                str += c;
                mp[c - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (mp[i]) {
                str += i + 'a';
                mp[i]--;
            }
        }
        return str;
    }
};