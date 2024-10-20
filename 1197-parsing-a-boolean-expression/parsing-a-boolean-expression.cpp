class Solution {

public:
    void traverse_stack(stack<char>& st) {
        if (st.empty())
            return;
        char x = st.top();
        st.pop();
        traverse_stack(st);
        cout << x << " ";
        st.push(x);
    }
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (auto& c : expression) {
            bool hasT = false;
            bool hasF = false;
            // traverse_stack(st);
            // cout<<endl;
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