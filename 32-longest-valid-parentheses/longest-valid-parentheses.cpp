class Solution {
public:
    int longestValidParentheses(string s) {
        // )((()())
        stack<int> st;
        int curr = INT_MAX,res = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(i);
            else{
                if(st.empty()){
                    //invalid substring
                    st = stack<int>();
                    curr = i+1;
                    continue;
                }
                int left = st.top();
                curr = min(curr,left);
                st.pop();
                if(st.empty())
                    res = max(res,i-curr+1);
                else
                    res = max(res,i-st.top());
            }
        }
        return res;
    }
};