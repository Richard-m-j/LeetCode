class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int numof1 = count(s.begin(), s.end(), '1');

        string ans;
        for(int i=0;i<numof1 - 1;i++)
            ans += "1";
        for(int i=0;i<n-numof1;i++)
            ans+= "0";
        ans += "1";
        return ans;
    }
};