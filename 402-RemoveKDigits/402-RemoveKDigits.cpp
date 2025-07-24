// Last updated: 7/24/2025, 8:31:12 AM
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    string removeKdigits(string& num, int k) {
        int n=num.size();
        if (n==k) return "0";
        vector<char> st;
        for(char c: num){// monotonic stack
            while(!st.empty() && c<st.back() && k>0){
                k--;
                st.pop_back();
             }
            st.push_back(c);            
        }
        while(k>0){
           st.pop_back();
            k--;
        }
        int j=0, m=st.size();
        while(st[j]=='0'&& j<m-1) j++;// Removing leading '0's
        string ans(st.begin()+j, st.end());
        return ans==""?"0":ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();