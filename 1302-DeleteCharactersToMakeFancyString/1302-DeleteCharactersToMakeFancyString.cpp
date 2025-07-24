// Last updated: 7/24/2025, 8:27:39 AM
class Solution {
public:
    string makeFancyString(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(s.length()<3)
            return s;
        string res = "";
        res += s[0];
        res += s[1];
        int k=1;
        for(int i=2;i<s.length();i++)
            if(s[i]!=res[k]||s[i]!=res[k-1]){
                res+=s[i];
                k++;
            }
        return res;
    }
};