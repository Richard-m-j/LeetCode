class Solution {

public:
    bool parseBoolExpr(string expression) {
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
        // cout<<st.top();
        return st.top() == 'f' ? false : true;
    }
};