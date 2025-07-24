// Last updated: 7/24/2025, 8:27:09 AM
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask = 0;
        int res = 0;
        vector<int> mp(32, -2);
        mp[0] = -1;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            switch (ch) {
                case 'a':
                    mask ^= 1;
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }
            int prev = mp[mask];
            if (prev == -2)
                mp[mask] = i;
            else
                res = max(res, i - prev);
        }
        return res;
    }
};