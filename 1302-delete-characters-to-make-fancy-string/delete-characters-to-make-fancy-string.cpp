class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3)
            return s;
        string res = "";
        res += s[0];
        res += s[1];
        for(int i=2;i<s.length();i++)
            if(s[i]!=res[res.length()-1]||s[i]!=res[res.length()-2])
                res+=s[i];
        return res;
    }
};