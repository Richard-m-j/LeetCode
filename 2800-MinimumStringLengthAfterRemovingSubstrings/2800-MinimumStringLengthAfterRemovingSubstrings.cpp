// Last updated: 7/24/2025, 8:23:11 AM
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top() == 'A' && s[i] == 'B')
                st.pop();
            else if(!st.empty() && st.top() == 'C' && s[i] == 'D')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();

    }
};