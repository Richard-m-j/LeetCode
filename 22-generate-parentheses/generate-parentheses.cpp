class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        stack<pair<string, pair<int, int>>> stk;
        stk.push({"(", {1, 0}});

        while (!stk.empty()) {
            auto [s, counts] = stk.top();
            stk.pop();
            int l = counts.first, r = counts.second;

            if (l == n && r == n) {
                res.push_back(s);
            } else {
                if (l < n)
                    stk.push({s + '(', {l + 1, r}});
                if (r < l)
                    stk.push({s + ')', {l, r + 1}});
            }
        }

        return res;
    }
};
