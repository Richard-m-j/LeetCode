// Last updated: 7/24/2025, 8:36:04 AM
class Solution {
public:
    int longestValidParentheses(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
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
                curr = min(curr,st.top());
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