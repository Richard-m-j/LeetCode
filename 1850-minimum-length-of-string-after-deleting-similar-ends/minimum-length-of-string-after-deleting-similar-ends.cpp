class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(0);
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r])
                break;
            char c = s[l];
            while (l <= r && s[l] == c)
                l++;
            while (l <= r && s[r] == c)
                r--;
        }
        if (l == r)
            return 1;
        return r - l + 1;
    }
};