// Last updated: 7/24/2025, 8:36:20 AM
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "(", 1, 0, n);
        return res;
    }
    void helper(vector<string>& res, string s, int l, int r, int n) {
        if (l == r && r == n) {
            res.push_back(s);
            return;
        }
        if (l < n)
            helper(res, s + '(', l + 1, r, n);
        if (r < l)
            helper(res, s + ')', l, r + 1, n);
    }
};