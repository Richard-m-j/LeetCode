class Solution {
public:
    int maxDepth(string s) {
        if(s == "" || s.length() == 1)
            return 0;
        int depth=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                depth++;
                ans =max(ans,depth);
            }
            if(s[i] == ')')
                depth--;
        }
        return ans;
    }
};