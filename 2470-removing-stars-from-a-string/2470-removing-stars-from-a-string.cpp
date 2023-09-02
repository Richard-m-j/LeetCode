class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
        int i{0},j{0};
        while(j<n)
        {
            if(s[j]=='*')
                i--;
            else
            {
                s[i]=s[j];
                i++;
            }
            j++;
        }
        if(i==-1)
            return "";
        return s.substr(0,i);
    }
};