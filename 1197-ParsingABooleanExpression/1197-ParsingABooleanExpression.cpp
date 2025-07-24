// Last updated: 7/24/2025, 8:27:52 AM
class Solution {
public:
    bool parseBoolExpr(string expression) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        stack<char> st;
        for (auto& c : expression) {
            bool hasT = false;
            bool hasF = false;

            if (c == ',')
                continue;
            if (c != ')') {
                st.push(c);
                continue;
            }
            while (st.top() != '(') {
                if (st.top() == 'f')
                    hasF = true;
                else if (st.top() == 't')
                    hasT = true;
                st.pop();
            }
            st.pop();
            char op = st.top();
            st.pop();
            char val;
            if (op == '!')
                val = hasT?'f':'t';
            else if (op == '|')
                val = hasT?'t':'f';
            else
                val = hasF?'f':'t';
            st.push(val);
        }
        return st.top() == 'f' ? false : true;
    }
};