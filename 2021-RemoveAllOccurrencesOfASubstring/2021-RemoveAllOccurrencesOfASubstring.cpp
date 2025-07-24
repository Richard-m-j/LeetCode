// Last updated: 7/24/2025, 8:25:33 AM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
            stack<char> temp;
            int j=part.length()-1;
            while(j>-1 && !st.empty()){
                if(st.top()!=part[j])
                    break;
                temp.push(st.top());
                st.pop();
                j--;
            }
            if(j!=-1){
                while(!temp.empty()){
                    st.push(temp.top());
                    temp.pop(); 
                }
            }
        }
        string res="";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};