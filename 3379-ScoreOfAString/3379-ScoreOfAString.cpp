// Last updated: 7/24/2025, 8:22:35 AM
class Solution {
public:
    int scoreOfString(string s) {
        int res=0;
        for(int i=0;i+1<s.length();i++)
            res += abs(s[i]-s[i+1]);
        return res;
    }
};